/*************************************************************************
	> File Name: demo.cpp
	> Author: Seottle
	> Mail: 874688169@qq.com
	> Created Time: Wed 20 Jul 2022 04:27:25 PM CST
 ************************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    LinkList* cur = node;
    while(cur != nullptr){
        if(cur->next = nullptr) break;
        Linklist cur_next = cur->next;
        while(cur_next != nullptr && cur->val == cur_next->val){
            Linklist tmp = cur_next;
            cur_next = cur_next->next;
            cur->next = cur_next;
            free(tmp);
        }
        cur = cur->next;
    }

    return 0;
}
