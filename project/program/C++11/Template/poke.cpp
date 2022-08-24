/*************************************************************************
	> File Name: poke.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 13 Aug 2022 04:30:22 PM CST
 ************************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    deque<int> Q;
    for(int i = 0; i < n; ++i){
        int t;
        cin >> t;
        Q.push_back(t);
    }
    vector<int> ans;
    
    while(!Q.empty()){
        int d = Q.back();
        ans.push_back(d);
        Q.pop_back();
        int a = Q.front();
        Q.pop_front();
        Q.push_back(a);
        int b = Q.front();
        Q.pop_front();
        Q.push_back(b);
    }
    for(auto i : ans){
        cout << i << " ";
    }
    return 0;
}
