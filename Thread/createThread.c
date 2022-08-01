/*************************************************************************
	> File Name: createThread.c
	> Author: Seottle
	> Mail: 874688169@qq.com
	> Created Time: Mon 11 Jul 2022 09:56:17 PM CST
 ************************************************************************/

#include<stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void printid(char *tip){
    pid_t pid= getpid();
    pthread_t tid = pthread_self();
    
    printf("%s pid :%u tid:%lu (%ld)\n", tip, pid, tid, tid);
    
}

void* thr_fun(void *arg){
    //todo
    printid(arg);
    return NULL;
}

int main(){
    pthread_t ntid;
    int ret;
    ret = pthread_create(&ntid, NULL, thr_fun,"new thread");
    if(ret){
        printf("create thread error:%s\n", strerror(ret));
        exit(1);
    }
    pthread_join(ntid, NULL);
    printid("main thread");
    return 0;
}
