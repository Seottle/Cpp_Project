/*************************************************************************
	> File Name: mmapOpt.c
	> Author: Seottle
	> Mail: 874688169@qq.com
	> Created Time: Wed 08 Jun 2022 04:28:29 PM CST
 ************************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
int main(){

    int fd = open("test.txt", O_RDWR);
    if(fd < 0){
        perror("open file");
        exit(1);
    }
    //int *p = mmap(NULL, 6, PROT_WRITE, MAP_SHARED, fd, 0);
    //p[0] = 0x30313233;
    
    char *p = mmap(NULL, 6, PROT_WRITE, MAP_SHARED, fd, 0);
    p[0] = 'A';
    p[2] = 'B';
    p[3] = 'C';
    munmap(p, 6);
    return 0;
}
