/*************************************************************************
	> File Name: sigMask.c
	> Author: Seottle
	> Mail: 874688169@qq.com
	> Created Time: Wed 06 Jul 2022 04:29:25 PM CST
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

void print_sig(const sigset_t *set){
    int i;
    for(i =  1; i < 32; ++i){
        if(sigismember(set, i)){
            putchar('1');
        }else{
            putchar('0');
        }
    }
    putchar(10);
}

int main(){
    sigset_t set ,oldset, pset;

    sigemptyset(&set);
    sigaddset(&set, SIGINT);
    sigaddset(&set, SIGQUIT);

    sigprocmask(SIG_BLOCK, &set, &oldset);
    /*
    int n = 5;
    while(n--){
        printf("proc sleep 1s\n");
        sleep(1);
    }*/
    //raise(SIGSEGV);
    //sleep(3);
    int n = 10;
    while(n--){
        sigpending(&pset);
        print_sig(&pset);
        sleep(1);
    }
    sigprocmask(SIG_SETMASK, &oldset, NULL);

    return 0;
}
