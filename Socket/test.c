/*************************************************************************
	> File Name: test.c
	> Author: Seottle
	> Mail: 874688169@qq.com
	> Created Time: Fri 22 Jul 2022 09:40:51 PM CST
 ************************************************************************/

#include<stdio.h>
#include<arpa/inet.h>

int main(){
    int a = 0x12345678;
    printf("%#x\n", a);
    int b = htonl(a);
    printf("%#x\n", b);

    return 0;
}
