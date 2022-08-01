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
    int fd = open("./hello.txt", O_WRONLY);
    if(fd < 0){
        perror("open");
        exit(1);
    }
    struct stat sta;
    fstat(fd, &sta);

    struct flock lock;
    lock.l_type = F_WRLCK;
    lock.l_pid = getpid();
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = sta.st_size;

    printf("pid : %d ", lock.l_pid);
    while(fcntl(fd, F_SETLK, &lock) < 0){
        perror("fcntl");
        struct flock lock_1;
        lock_1 = lock;
        lock_1.l_type = F_WRLCK;
        
        fcntl(fd, F_GETLK, &lock_1);
        switch(lock_1.l_type){
            case F_UNLCK:
                printf("get no lock\n");
                break;
            case F_RDLCK:
                printf("get read lock of pid = %d\n", lock_1.l_pid);
                break;
            case F_WRLCK:
                printf("get write lock of pid = %d\n", lock_1.l_pid);
                break;
        }

        sleep(1);
    }
    printf("set write lock succeccful\n");
    getchar();
    close(fd);
    return 0;
}
