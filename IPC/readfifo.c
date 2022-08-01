/*************************************************************************
	> File Name: readfifo.c
	> Author: Seottle
	> Mail: 874688169@qq.com
	> Created Time: Fri 01 Jul 2022 04:13:23 PM CST
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
int main(){
    char buf[20];
    
    int fd = open("./tube", O_RDONLY);
    if(fd < 0){
        perror("open"); 
        exit(1); 
    }
    perror("open");

    ssize_t n = read(fd, buf, 20);
    printf("read %ld types \n", n);
    write(1, buf, 20);

    close(fd);
    return 0;
}
