/*************************************************************************
	> File Name: client.c
	> Author: Seottle
	> Mail: 874688169@qq.com
	> Created Time: Thu 28 Jul 2022 05:11:21 PM CST
 ************************************************************************/

#include<stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <arpa/inet.h>
#include<unistd.h>
#include <stdlib.h>
#include <pthread.h>

#define SERV_PORT 8000
#define MAXLINE 80
// 定义多行宏用 \' 
#define perrorexit(msg){\
    perror(msg); \
    exit(1); \
}
int main(){
    struct sockaddr_in serveraddr;
    int sockfd;
    char buf[MAXLINE];

    sockfd = socket(AF_INET, SOCK_DGRAM,0);

    bzero(&serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(SERV_PORT);
    inet_pton(AF_INET, "172.17.173.106", &serveraddr.sin_addr);
    int n; 
    while(n = read(0, buf, MAXLINE)){
        n = sendto(sockfd, buf, n, 0, (struct sockaddr*)&serveraddr, sizeof(serveraddr));
        
        n = recvfrom(sockfd,buf, MAXLINE,0,NULL,0);
        write(1, buf, n);
    }
    close(sockfd);
    return 0;
}
