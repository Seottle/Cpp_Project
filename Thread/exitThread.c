/*************************************************************************
	> File Name: exitThread.c
	> Author: Seottle
	> Mail: 874688169@qq.com
	> Created Time: Tue 12 Jul 2022 10:16:05 AM CST
 ************************************************************************/

#include<stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
void *thr_fn1(void *arg){
    printf("Thread 1 returing\n");
    return (void *)1;
}

void *thr_fn2(void *arg){
    printf("Thread 2 exiting\n");
    pthread_exit((void *)2);
    return NULL;
}

void *thr_fn3(void *arg){
    while(1){
        printf("Thread 3 sleeping\n");
        sleep(1);
    }    
    return NULL;
}


int main(){
    pthread_t  tid;
    void* sts;

    pthread_create(&tid, NULL, thr_fn1, NULL);
    pthread_join(tid, &sts);
    printf("Thread 1 exit code %ld\n",(long)sts);

    pthread_create(&tid, NULL, thr_fn2, NULL);
    pthread_join(tid, &sts);
    printf("Thread 2 exit code %ld\n",(long)sts);

    pthread_create(&tid, NULL, thr_fn3, NULL);
    sleep(3);
    pthread_cancel(tid);
    pthread_join(tid, &sts);
    printf("Thread 3 exit code %ld\n",(long)sts);
    return 0;
}
