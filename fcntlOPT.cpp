/*************************************************************************
	> File Name: fcntlOPT.cpp
	> Author: Seottle
	> Mail: 874688169@qq.com
	> Created Time: Tue 07 Jun 2022 08:26:44 PM CST
 ************************************************************************/

#include<iostream>
#include<bits/stdc++.h>
#include<fcntl.h>
using namespace std;
int main(int argc, char **argv){
    if(argc < 2){
        printf("usage:cmd df\n");
        exit(1);
    }
    int flags = fcntl(atoi(argv[1]), F_GETFL);
    if(flags < 0){
        perror("fcntl get flags");
        exit(1);
    }
    switch(flags & O_ACCMODE){
        case O_RDONLY:
            printf("read only");
            break;
        case O_WRONLY:
            printf("write only");
            break;
        case O_RDWR:
            printf("read write");
            break;
        default:
            printf("invalid access mode \n");
    }
    if(flags & O_APPEND){
        printf(", append");
    }
    if(flags & O_NONBLOCK){
        printf(", nonblock");
    }
    putchar(10);
    return 0;
}
