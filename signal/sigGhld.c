/*************************************************************************
	> File Name: sigGhld.c
	> Author: Seottle
	> Mail: 874688169@qq.com
	> Created Time: Thu 07 Jul 2022 04:37:28 PM CST
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

void sig_child(int signo){
    int sts;
    wait(&sts);
    if(WIFEXITED(sts)){
        printf("exit with code %d\n", WEXITSTATUS(sts));
    }else{
        printf("Lemon %d\n", WEXITSTATUS(sts));
    }
    return;
}

int main(){
    pid_t pid = fork();
    if(pid < 0){
        perror("fork");
        exit(1);
    }

    if(pid){
    //parent
        struct sigaction newact, oldact;
        newact.sa_handler = sig_child;
        sigemptyset(&newact.sa_mask);
        newact.sa_flags = 0;
        
        sigaction(SIGCHLD, &newact, &oldact);

        int n = 10;
        while(n--){
            printf("woring \n");
            sleep(1);
        }
        
    }else{
    //child
        sleep(3);
        exit(3);
    }
    



    return 0;
}
