/*************************************************************************
	> File Name: popenOpt.c
	> Author: Seottle
	> Mail: 874688169@qq.com
	> Created Time: Fri 01 Jul 2022 04:03:22 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int main(){
    FILE *fp = popen("cat hello.txt", "r");
    if(!fp){
        perror("popen");
        exit(1);
    }
    char c;
    while(~(c = fgetc(fp))){
        putchar(toupper(c));
    }
    pclose(fp);
    
    return 0;
}
