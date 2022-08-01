/*************************************************************************
	> File Name: condi.c
	> Author: Seottle
	> Mail: 874688169@qq.com
	> Created Time: Thu 14 Jul 2022 11:26:09 AM CST
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

typedef struct Goods{
    int data;
    struct Goods *next;
}Goods;

Goods *head = NULL;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t buffer = PTHREAD_COND_INITIALIZER;


void *producer(void *arg){
    Goods *ng;
    while(1){ 
        ng = (Goods*)malloc(sizeof(Goods));
        ng -> data = rand() % 100;
        //头插
        pthread_mutex_lock(&mutex);
        ng -> next = head;
        head = ng;
        pthread_mutex_unlock(&mutex);
        pthread_cond_signal(&buffer);

        printf("produce %d \n", ng -> data);
        sleep(rand()%3);
    }
}
void *consumer(void* arg){
    Goods* ng;
    while(1){
        pthread_mutex_lock(&mutex);
        while(!head){
            pthread_cond_wait(&buffer, &mutex);   
        }
        ng = head;
        head = head -> next;
        pthread_mutex_unlock(&mutex);
        
        printf("consume %d \n", ng -> data);
        free(ng);
        sleep(rand()%3); 
    }

}
int main(){
    srand(time(NULL));
    pthread_t pid, cid1, cid2, cid3,cid4;
    pthread_create(&pid, NULL, producer, NULL);

    pthread_create(&cid1, NULL, consumer, NULL);
    pthread_create(&cid2, NULL, consumer, NULL);
    pthread_create(&cid3, NULL, consumer, NULL);
    pthread_create(&cid4, NULL, consumer, NULL);

    pthread_join(pid, NULL);

    pthread_join(cid1, NULL);
    pthread_join(cid2, NULL);
    pthread_join(cid3, NULL);
    pthread_join(cid4, NULL);
    return 0;
}
