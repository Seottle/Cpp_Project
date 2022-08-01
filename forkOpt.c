/*************************************************************************
	> File Name: forkOpt.c
	> Author: Seottle
	> Mail: 874688169@qq.com
	> Created Time: Thu 16 Jun 2022 09:17:20 PM CST
 ************************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
int main(){
    char *msg;
    int n;
    pid_t pid = fork();
    if(pid < 0){
        perror("fork");
        exit(1);
    }
    if(pid == 0){
        n = 6;
        for(int i = 0; i < n; ++i){
            sleep(1);
            printf("child self = %d, parent = %d \n", getpid(), getppid());
        }
    }else{
        n = 3;
        for(int i = 0; i < n; ++i){
            sleep(1);
            printf("father self = %d, parent = %d \n", getpid(), getppid());
        }
    }
    return 0;
}
