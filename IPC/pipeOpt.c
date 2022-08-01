/*************************************************************************
	> File Name: pipeOpt.c
	> Author: Seottle
	> Mail: 874688169@qq.com
	> Created Time: Thu 30 Jun 2022 08:03:45 PM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(){
    pid_t pid;
    int fd[2];
    char buf[20];
    if(pipe(fd) < 0){
        perror("pipe");
        exit(1);
    }
    
    pid = fork();
    if(pid < 0){
        perror("fork");
        exit(1);
    }
    int n;
    // 0 是输入 1是输出
    if(pid > 0){
        close(fd[0]);
        write(fd[1], "hellow pipe\n", 11);
        wait(NULL);
    }else{
        close(fd[1]);
        n = read(fd[0], buf, 20);
        write(1, buf, n);
    }
    return 0;
}
