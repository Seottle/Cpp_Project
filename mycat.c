/*************************************************************************
	> File Name: nonblock.c
	> Author: Seottle
	> Mail: 874688169@qq.com
	> Created Time: Wed 01 Jun 2022 08:42:51 PM CST
 ************************************************************************/

#include<stdio.h>
 
int main(int argc, char *argv[]){
    if(argc < 2){
        printf("usage:cmd + filename\n");
        return 1;
    }
    FILE *fp = fopen(argv[1], "r");
    if(!fp){
        perror("open file");
        return 1;
    }
    
    char c;
    while((c = fgetc(fp)) != EOF){
        printf("%c", c);
    }

    fclose(fp);
    return 0;
}
