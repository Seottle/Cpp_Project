/*************************************************************************
	> File Name: deamon.c
	> Author: Seottle
	> Mail: 874688169@qq.com
	> Created Time: Fri 15 Jul 2022 10:37:28 AM CST
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(){

    pid_t pid = fork();
    if(pid < 0){
        perror("fork");
        exit(1);
    }
    if(pid){
        exit(0);
    }else{
        pid_t nsid = setsid();
        printf("new session id is %d\n", nsid);

    }
    return 0;
}
