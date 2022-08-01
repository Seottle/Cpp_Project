/*************************************************************************
	> File Name: sem.c
	> Author: Seottle
	> Mail: 874688169@qq.com
	> Created Time: Thu 14 Jul 2022 03:48:28 PM CST
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#define NUM 5

int q[NUM];

sem_t blank, goods;
int head, tail;
void* producer(){
    int i = 0;
    while(1){
        sem_wait(&blank);
        q[i] = rand() % 100 + 1;
        printf("produce %d \n", q[i]);
        i = (i + 1) % NUM;
        sem_post(&goods);
        sleep(rand() %3);
    }

}
void* consumer(){
    int i = 0;
    while(1){
        sem_wait(&goods);
        printf("consume %d \n", q[i]);
        q[i] = 0;
        i = (i + 1) % NUM;
        sem_post(&blank);
        sleep(rand()%3);
    }

}
int main(){
    srand(time(NULL));
    //第二个参数是写共享内存的位置
    sem_init(&blank, 0, NUM);
    sem_init(&goods, 0, 0);
    pthread_t pid, cid;

    pthread_create(&pid, NULL, producer, NULL);
    pthread_create(&cid, NULL, consumer, NULL);
    
    pthread_join(pid, NULL);
    pthread_join(cid, NULL);
    return 0;
}
