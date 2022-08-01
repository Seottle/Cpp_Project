/*************************************************************************
	> File Name: forkexec.c
	> Author: Seottle
	> Mail: 874688169@qq.com
	> Created Time: Fri 17 Jun 2022 04:03:31 PM CST
 ************************************************************************/

#include<stdio.h>
#include <errno.h>
#include <stdlib.h>
 
#include <string.h>
char command[256];
int main(){
    int rtn;
    while(1){
        printf(">");
        fgets(command, 256, stdin);
    }
    command[strlen(command) - 1] = 0;
    if(fork() == 0){
        execlp(command, NULL);
        perror(command);
        exit(errno);
    }else{
        wait(&rtn);
        printf("child process return %d\n", rtn);
    }

    return 0;
}
