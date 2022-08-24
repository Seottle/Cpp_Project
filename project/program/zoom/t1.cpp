/*************************************************************************
	> File Name: t1.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 11 Aug 2022 09:51:19 PM CST
 ************************************************************************/
#include <bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
    string str;
    while(cin >> str){
        int left = 0;
        int cnt = 1;
        int ret = 0;
        for(int i = 0; i < str.size(); ++i){
            char c = str[i];
            if(c != '(' && c != ')') {
                left = 0;
                cnt = 1;
                continue;
            }
            if(c == '('){
                left++;
                cnt *= 2;
            }else{
                left--;
            }
            
            if(left == 0) {
                ret += cnt;
            }
            if(left == -1) left = 0;
        }
        cout << str.size() - ret << endl;
    }

    return 0;
}
