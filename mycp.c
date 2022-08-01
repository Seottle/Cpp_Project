/**********************:
 ***************************************************
	> File Name: mycp.c
	> Author: Seottle
	> Mail: 874688169@qq.com
	> Created Time: Thu 02 Jun 2022 10:20:32 AM CST
 ************************************************************************/

#include<stdio.h>

int main(int argc, char *argv[]){
    if(argc < 3){
        printf("usage error: cmd + srcfilename + dstfilename\n");
        return -1;
    }
    FILE *srcfp = fopen(argv[1], "r");
    if(!srcfp){
        perror("open srcfile");
        return -1;
    }
    
    FILE *dstfp = fopen(argv[2], "w");
    if(!dstfp){
        perror("open dstfile");
        return -1;
    }
    char c;
    while((c =fgetc(srcfp)) != EOF){
        fputc(c, dstfp);
    }
    
    fclose(dstfp);
    fclose(srcfp);
    return 0;
}
