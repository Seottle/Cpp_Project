/*************************************************************************
	> File Name: server.c
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


#define SERV_PORT 9900
#define MAXLINE 80
// 定义多行宏用 \' 
#define perrorexit(msg){\
    perror(msg); \
    exit(1); \
}
void* up_server(void* argv){
    
    pthread_detach(pthread_self());

    int connfd = (int)argv;
    char buf[MAXLINE];
    while(1){
            
        int n = read(connfd, buf, MAXLINE);
        if(!strncmp(buf, "quit", 4))
            break;
        write(1, buf, n);
        for(int i = 0; i < n; ++i){
            buf[i] = toupper(buf[i]);
        }
        write(connfd, buf, n);
    }
    close(connfd);
}
int main(){

    struct sockaddr_in serveraddr, clientaddr;
    int listenfd, connfd;
    int clientaddr_len;
    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if(listenfd < 0)
        perrorexit("socket");
    
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
        clientaddr_len = sizeof(clientaddr);
        connfd = accept(listenfd, (struct sockaddr*)&clientaddr, &clientaddr_len);
        if(connfd < 0)
            perrorexit("accept");
        printf("received from %s:%d\n", 
               inet_ntop(AF_INET, &clientaddr.sin_addr, str, sizeof(str)), ntohs(clientaddr.sin_port));
        //ntop 是把网络字节序转成点分十进制的ip地址 
        
        /*多进程版本 
        pid_t pid = fork();
        if(pid < 0)
            perrorexit("fork");
        if(pid > 0){
            close(connfd);
            while(waitpid(-1, NULL, WNOHANG) > 0){}
            continue;
        }

        close(listenfd);
        */
        /* 
        while(1){
            
            int n = read(connfd, buf, MAXLINE);
            if(!strncmp(buf, "quit", 4))
                break;
            write(1, buf, n);
            for(int i = 0; i < n; ++i){
                buf[i] = toupper(buf[i]);
            }
            write(connfd, buf, n);
        }
        close(connfd);
        */
        pthread_t tid;
        pthread_create(&tid, NULL, up_server, (void*)connfd);
        printf("new thread is %#lx\n", tid);
    }
    return 0;
}
