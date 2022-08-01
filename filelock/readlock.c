/*************************************************************************
	> File Name: fcntlOpt.c
	> Author: Seottle
	> Mail: 874688169@qq.com
	> Created Time: Thu 14 Jul 2022 04:26:04 PM CST
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
    int fd = open("./hello.txt", O_RDONLY);
    if(fd < 0){
        perror("open");
        exit(1);
    }
    struct stat sta;
    fstat(fd, &sta);

    struct flock lock;
    lock.l_type = F_RDLCK;
    lock.l_pid = getpid();
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = sta.st_size;

    printf("pid : %d ", lock.l_pid);
    if(fcntl(fd, F_SETLK, &lock) < 0){
        perror("fcntl");
        exit(1);
    }else{
        printf("add read lock succeccful\n");
    }

    sleep(20);
    close(fd);
    return 0;
}
