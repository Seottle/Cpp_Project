/*************************************************************************
	> File Name: demo.c
	> Author: Seottle
	> Mail: 874688169@qq.com
	> Created Time: Tue 05 Jul 2022 11:25:59 AM CST
 ************************************************************************/

#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include <string.h>
#include <sys/ipc.h>
#include<sys/wait.h>
#include<sys/shm.h>
int main(){
    sleep(2);
    abort();
    return 0;
}
