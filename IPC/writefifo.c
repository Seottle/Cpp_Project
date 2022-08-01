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
    
    
    int fd = open("./tube", O_WRONLY);
    if(fd < 0){
        perror("open"); 
        exit(1); 
    }
    perror("open");

    write(fd, "hello FIFO\n", 11);

    close(fd);
    return 0;
}
