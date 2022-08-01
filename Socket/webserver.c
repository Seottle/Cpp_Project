/*************************************************************************
	> File Name: Threadpool.c
	> Author: Seottle
	> Mail: 874688169@qq.com
	> Created Time: Sat 23 Jul 2022 10:09:36 PM CST
 ************************************************************************/

#include<stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <arpa/inet.h>
#include<unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/epoll.h>

#define SERV_PORT 1234 
#define MAXLINE 8000
// 定义多行宏用 \' 
#define perrorexit(msg){\
    perror(msg); \
    exit(1); \
}

typedef struct Task{
    int fd;
    struct Task* next;
}Task;

typedef struct Task_pool{
    Task* head;
    Task* tail;
    pthread_mutex_t mutex; //互斥锁
    pthread_cond_t havetask;//条件锁
}Task_pool;

Task_pool* task_pool_init(){
    Task_pool* tp = (Task_pool*)malloc(sizeof(Task_pool));
    tp->head=NULL;
    tp->tail=NULL;
    pthread_mutex_init(&tp->mutex,NULL);
    pthread_cond_init(&tp->havetask,NULL);
    return tp;
}

void task_pool_push(Task_pool* tp, int fd){
    pthread_mutex_lock(&tp->mutex);

    Task* t = (Task*)malloc(sizeof(Task));
    t->fd = fd;
    t->next = NULL;
    //在队列后面插入
    if(tp->tail != NULL){
        tp->tail->next = t;
        tp->tail = t;
    }else{
        tp->head = tp->tail = t;
    }
    
    pthread_cond_broadcast(&tp->havetask);
    pthread_mutex_unlock(&tp->mutex);
}

Task task_pool_pop(Task_pool* tp){
    pthread_mutex_lock(&tp->mutex);
    
    while(tp->head == NULL){
        pthread_cond_wait(&tp->havetask, &tp->mutex);//等待条件成立，把刚才抢到的锁扔掉
    }
    Task node, *del;
    del = tp->head;
    node = *del;
    tp->head = tp->head->next;
    if(!tp->head) tp->tail = NULL;
    
    free(del);

    pthread_mutex_unlock(&tp->mutex);
    return node;
}

void task_pool_free(Task_pool *tp){
    Task* p=tp->head, *del;
    
    while(p){
        del = p;
        p = p->next;
        free(del);
    }
    tp->head = NULL; //避免悬空指针！！
    pthread_mutex_destroy(&tp->mutex);
    pthread_cond_destroy(&tp->havetask);
    free(tp);
}

void* up_server(void* argv){
    
    pthread_detach(pthread_self());

    char buf[MAXLINE];
     
    while(1){
        Task_pool *tp = argv;
        Task t = task_pool_pop(tp);
        int connfd = t.fd;
        printf("get task fd=%d\n", connfd);
            
        int n = read(connfd, buf, MAXLINE);
        write(1, buf, n);
        //for(int i = 0; i < n; ++i){
        //    buf[i] = toupper(buf[i]);
        //}
        write(connfd, buf, n);
        printf("finish task fd=%d\n", connfd);
        
        //if(!strncmp(buf, "QUIT", 4))
        close(connfd);
    }
    return (void*)0;
}
int main(){
    
    Task_pool* tp = task_pool_init();
    
    //多线程 + 线程池
    pthread_t tid;
    
    for(int i = 0; i < 4; ++i){
        pthread_create(&tid, NULL, up_server, tp);
        printf("new thread is %#lx\n", tid);
    }
    struct sockaddr_in serveraddr, clientaddr;
    int listenfd, connfd;
    int clientaddr_len;
    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if(listenfd < 0)
        perrorexit("socket");

    //用epoll去监听需求，故要在listen之后
    //创建一个epoll    epoll_create
    int epfd = epoll_create(256);
    struct epoll_event ev, events[256];
    ev.events = EPOLLIN | EPOLLET;
    ev.data.fd = listenfd;
    //用epoll_ctl() 对监听的事件操作
    epoll_ctl(epfd, EPOLL_CTL_ADD, listenfd, &ev);

    bzero(&serveraddr, sizeof(serveraddr));
    char str[INET_ADDRSTRLEN];
    char buf[MAXLINE];
    //服务器ip地址：端口初始化
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(SERV_PORT);//主机host字节序转成网络net字节序
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
    
    if(bind(listenfd, (struct sockaddr*)&serveraddr, sizeof(serveraddr)) <0)
        perrorexit("bind");
    
    if(listen(listenfd, 3) < 0)
        perrorexit("listen");
    printf("Accpeting connection ...\n");

    while(1){
        // 用epoll_wait等待事件的发生,返回的是有多少个线程在该lisentfd中 
        int nfds = epoll_wait(epfd, events, 256, -1); //-1表示阻塞等待
        for(int i = 0; i < nfds; ++i){
            if(events[i].data.fd == listenfd){
                clientaddr_len = sizeof(clientaddr);
                connfd = accept(listenfd, (struct sockaddr*)&clientaddr, &clientaddr_len);
                if(connfd < 0)
                    perrorexit("accept");
                printf("received from %s:%d\n", 
                inet_ntop(AF_INET, &clientaddr.sin_addr, str, sizeof(str)), ntohs(clientaddr.sin_port));
               
                //新进来的事件要把他的fd加入到  events队列中
                ev.events = EPOLLIN | EPOLLET;
                ev.data.fd = connfd;
                epoll_ctl(epfd, EPOLL_CTL_ADD, connfd, &ev);

                //task_pool_push(tp, connfd);
            }else if(events[i].events & EPOLLIN){
                int clientfd = events[i].data.fd;
                if(clientfd < 3)
                    continue;
                
                task_pool_push(tp, clientfd);
            }
        }




    }
    task_pool_free(tp);
    return 0;
}
