/*************************************************************************
	> File Name: test2.cpp
	> Author: Seottle
	> Mail: 874688169@qq.com
	> Created Time: Wed 20 Jul 2022 07:13:36 PM CST
 ************************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int cal(string s){
    stack<int> number;
    stack<char> sign;
    int start = 0, end = 0, size = s.size();
    while(end < size){
        if(str[end] == '('){//遇到左括号，左括号里面的数都要去递归计算
            int flag = 1;
            for(end = start + 1; end < size; ++end){
                if(str[end] == '(') flag++;
                   if(str[end] == ')'){
                       flag--;
                       if(flag == 0){ //括号匹配完了，退出
                           break;
                       }
                   }
            }
            number.push(cal(s.substr(start + 1, end - start - 1)));
            
        }
    }
}

int main(){
    string str = "2+3-(5+2)";
    
    return 0;
}
