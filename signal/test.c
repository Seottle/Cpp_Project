/*************************************************************************
	> File Name: test.c
	> Author: Seottle
	> Mail: 874688169@qq.com
	> Created Time: Tue 05 Jul 2022 10:55:06 AM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include <string.h>
#include <sys/ipc.h>
#include<sys/wait.h>
#include<sys/shm.h>

int main(){
    /*
    pid_t pid = fork();
    if(pid < 0){
        perror("fork");
        exit(1);
    }
    if(pid){
        sleep(3);
        if(kill(pid, SIGQUIT) < 0){
            perror("kill");
            exit(1);
        }
        int sts;
        wait(&sts);
        if(WIFSIGNALED(sts)){
            printf("child terminate by signal %d\n", WTERMSIG(sts));
        }else{
            printf("another reasons\n");
        }
    }else{
        while(1){
            printf("sleep now\n");
            sleep(1);
        }
    }
    */
    int pfd[2];
    

    return 0;
}
