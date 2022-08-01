/*************************************************************************
	> File Name: shmopt.c
	> Author: Seottle
	> Mail: 874688169@qq.com
	> Created Time: Fri 01 Jul 2022 07:13:53 PM CST
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include <string.h>
#include <sys/ipc.h>
#include<sys/shm.h>
#include <wait.h>
int main(){
    
    key_t key = ftok("./hello.txt", 9);
    if(key < 0){
        perror("ftok");
        exit(1);
    }
   
    printf("key = 0x%x\n", key);
    int shmid = shmget(key, 20, IPC_CREAT | 0666);
    if(shmid < 0){
        perror("shmget");
        exit(1);
    }
    printf("shmid = %d\n", shmid);

    //void* shmp = shmat(shmid, NULL, 0);
    
    char* shmp = shmat(shmid, NULL, 0);
    if(shmp < 0){
        perror("shmat");
        exit(1);
    }

    printf("shmp = %p\n", shmp);

    //snprintf(shmp, 20, "hello\n");

    printf("%s", shmp);
    
    bzero(shmp, 20);
    pid_t pid = fork();
    if(pid < 0){
        perror("fork");
        exit(1);
    }
    
    if(pid){
        //parent
        while(1){
            scanf("%s", shmp);
            if(!strcmp(shmp, "q")){
                break;
            }
        }
        wait(NULL);
    }else{
        //child
        while(1){
            if(!strcmp(shmp, "q")){
                bzero(shmp, 20);
                break; 
            }
            if(*shmp) {
                printf("child read :%s\n", shmp);
                bzero(shmp, 20);
            }
            sleep(1);
        }
    }
    shmdt(shmp);
    return 0;
}
