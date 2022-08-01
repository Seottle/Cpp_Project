/*************************************************************************
	> File Name: e-dict.cpp
	> Author: Seottle
	> Mail: 874688169@qq.com
	> Created Time: Mon 23 May 2022 07:10:51 PM CST
 ************************************************************************/

#include<iostream>
#include<bits/stdc++.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;

#define MAXLEN 2048
typedef struct Node{
    char* wd;
    char* trans;
    struct Node* next;
}Node;
//加载单词
Node* loadDict(){
    Node* head = NULL;
    char buff[MAXLEN];
    FILE *fp = fopen("./dict.txt", "r");
    if(!fp){
        perror("open dict");
        exit(1);
    }

    while(fgets(buff, MAXLEN, fp)){
        Node* nn = (Node*)malloc(sizeof(Node));
        
        nn -> wd = (char*)malloc(sizeof(char) * (strlen(buff)));
        strcpy(nn -> wd, buff);
        nn -> wd[strlen(nn -> wd) - 1] = 0;
        
        fgets(buff, MAXLEN, fp);
        nn -> trans = (char*)malloc(sizeof(char) * (strlen(buff)));
        strcpy(nn -> trans, buff);
        nn -> trans[strlen(nn -> trans) - 1] = 0;
    
        //新节点插入链表  头插法
        nn -> next = head;
        head = nn;
    }
    //关闭文件
    fclose(fp);
    return head;
}

//查找单词
Node* findNode(Node* head, char* wd){
    while(head && strcmp(wd,head->wd))
        head = head -> next;
        
    return head;
}
//查找字典
void findDict(Node* head){
    char wd[MAXLEN];
    while(1){
        printf("plz input a word :");
        scanf("%s", wd);
        if(!strcmp(wd,"q!")) break;//判断字符串相等不能用==，这是判断值相等的！

        //从链表中查找该单词的结点
        Node* fn = findNode(head, wd);
        if(fn){
            printf("%s\n%s\n", fn -> wd, fn -> trans);
        }else{
            printf("Not found!\n");
        }
    }
    printf("bye~~~\n");
}
void testlist(Node* head){
    while(head){
        cout << "Word : " << head->wd << endl;
        
        

         
        head = head -> next;
    }
    return;
}
int main(){
    //加载字典数据到内存
    Node* head = loadDict();
    testlist(head);
    //查询字典
    findDict(head);
    //释放内存
    //freeDict();
    return 0;
}
