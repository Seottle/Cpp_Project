/*************************************************************************
	> File Name: HW1.1.cpp
	> Author: Seottle
	> Mail: 874688169@qq.com
	> Created Time: Thu 23 Jun 2022 09:54:39 AM CST
 ************************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    string str;
    while(cin >> str){
        int n = str.size();
        int ans = 0;
        //for(int i = 0; i < n; ++i){
            stack<char> S;
            int len = 0;
            for(int j = 0; j < n; ++j){
                if(str[j] == '('){
                    S.push(str[j]);
                }else {
                    if(S.empty()){
                        ans = max(ans, len);
                        len = 0;
                    }else{
                        
                        S.pop();
                        len += 2;
                    }    
                }
            }
            ans = max(len, ans);
        //}
        cout << ans << endl;
    }


    return 0;
}
