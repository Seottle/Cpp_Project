/*************************************************************************
	> File Name: clent.c
	> Author: Seottle
	> Mail: 874688169@qq.com
	> Created Time: Wed 27 Jul 2022 04:22:29 PM CST
 ************************************************************************/

#include<stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <ctype.h>
#include <arpa/inet.h>
#define SERV_PORT 9999
#define MAXLINE 80
int main(){
    
    struct sockaddr_in serveraddr;

    char buf[MAXLINE] = {"hello zhengxiaotao"};
    
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    bzero(&serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(SERV_PORT);
    inet_pton(AF_INET, "172.17.173.106", &serveraddr.sin_addr);
    

    connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr));
    int n;
    while(n = read(0, buf, MAXLINE)){
        write(sockfd, buf, n);
        if(!strncmp(buf, "quit", 4))
            break;
        n = read(sockfd, buf, MAXLINE);//从服务器上读
        printf("response from server:\n");
        write(1, buf, n);
    }
    close(sockfd);

    return 0;
}
