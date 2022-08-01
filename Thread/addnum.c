/*************************************************************************
	> File Name: addnum.c
	> Author: Seottle
	> Mail: 874688169@qq.com
	> Created Time: Tue 12 Jul 2022 10:44:40 AM CST
 ************************************************************************/

#include<stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

pthread_mutex_t add_mutex = PTHREAD_MUTEX_INITIALIZER;

int cnt = 0;
void* cntadd(void *arg){
    int val, i;

    for(i = 0; i < 5000; ++i){
        pthread_mutex_lock(&add_mutex);
        val = cnt;
        printf("%p: %d\n", (void*)pthread_self(), val);
        cnt = val + 1;
        pthread_mutex_unlock(&add_mutex);
    }
    return NULL;
}

int main(){
    pthread_t tida, tidb;

    pthread_create(&tida, NULL, cntadd, NULL);
    pthread_create(&tidb, NULL, cntadd, NULL);
    
    pthread_join(tida, NULL);
    pthread_join(tidb, NULL);

    return 0;
}
