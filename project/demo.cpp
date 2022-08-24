/*************************************************************************
	> File Name: demo.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 23 Aug 2022 07:16:59 PM CST
 ************************************************************************/

#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    string str;
    while(getline(cin, str)){
        int n = str.size();
        vector<string> ans;
        string tmp = "";
        for(int i = 0; i < n; ++i){
            if(str[i] == ' '){
                ans.push_back(tmp);
                tmp.clear();
            }else tmp.push_back(str[i]);
        } 
        if(!tmp.empty()) ans.push_back(tmp); 
        
        for(int i = ans.size() - 1; i >= 0; --i){
            if(i != 0)cout << ans[i] << " ";
            else cout << ans[i];
        }
        cout << endl; 
    }
    return 0; 
}
