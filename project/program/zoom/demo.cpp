/*************************************************************************
	> File Name: demo.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 10 Aug 2022 08:18:27 PM CST
 ************************************************************************/

#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int n, k;
string s;
int ret = 0;
void dfs(int i, int l, int cnt){
    if(cnt >= k){
        ret++;
    }
    if(i == s.size()) return ;
    if(s[i] == '(') dfs(i + 1, l + 1, cnt);
    else dfs(i + 1, l, cnt + l);
}

int main(){
    
   // while(cin >> n >> k){
        cin >> n >> k;
        cin >> s;
        dfs(0, 0, 0);
        cout << ret << endl;
    //}
    
    return 0;
}
