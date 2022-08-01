/*************************************************************************
	> File Name: msgOpt.c
	> Author: Seottle
	> Mail: 874688169@qq.com
	> Created Time: Mon 04 Jul 2022 04:50:52 PM CST
 ************************************************************************/


#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include <string.h>
#include <sys/ipc.h>
#include<sys/shm.h>
#include <sys/msg.h>

#define MSGLEN 20
typedef struct msgbuf{
    long mtype;
    char mtext[MSGLEN];

}MSG;
int main(){
    key_t key = ftok("./tube", 9);
    printf("key = %#x\n", key);


    int mqid = msgget(key, IPC_CREAT | 0666);
    printf("mqid = %d\n", mqid);
    
    MSG msg;
    msg.mtype = 1;
    strncpy(msg.mtext, "hi, how are you?\n", MSGLEN);
    msgsnd(mqid, &msg, MSGLEN, 0);



    msg.mtype = 2;
    strncpy(msg.mtext, "xiaokao:online?\n", MSGLEN);
    msgsnd(mqid, &msg, MSGLEN, 0);

    return 0;
}
