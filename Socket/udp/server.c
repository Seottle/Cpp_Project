/*************************************************************************
	> File Name: server.c
	> Author: Seottle
	> Mail: 874688169@qq.com
	> Created Time: Thu 28 Jul 2022 04:28:42 PM CST
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
    int sockfd;
    struct sockaddr_in serveraddr, clientaddr;
    socklen_t clientaddr_len;
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    char buf[MAXLINE];
    bzero(&serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serveraddr.sin_port = htons(SERV_PORT);
    
    if(bind(sockfd, (struct sockaddr*)&serveraddr, sizeof(serveraddr))<0)
        perrorexit("bind");
    printf("udp server ready~\n");

    int n;
    while(1){
        n = recvfrom(sockfd, buf, MAXLINE, 0, (struct sockaddr*)&clientaddr, &clientaddr_len);
        if(n<0){
            perrorexit("recvfrom");
        }
        for(int i = 0; i < n; ++i){
            buf[i] = toupper(buf[i]);
        }
        sendto(sockfd, buf, n, 0, (struct sockaddr*)&clientaddr, sizeof(clientaddr));
    }
    close(sockfd);
    return 0;
}
