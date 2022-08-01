/*************************************************************************
	> File Name: test2.cpp
	> Author: Seottle
	> Mail: 874688169@qq.com
	> Created Time: Wed 15 Jun 2022 07:52:06 PM CST
 ************************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    string a, b;
    cin >> a >> b;
    string ans = "";
    bool flag1 = true;
    //for(int i = 0; i < b.size(); ++i){
        int left = 0;
        int right = 0;
        int c = left;
        bool flag = true;
        for(int j = left; j < a.size(); ++j){
            if(b[0] == a[j] && flag){
                left = j;
                flag = false;
            }
            if(b[right] == a[j]){
                right++;
            }
            if(right == b.size()){
                cout << "left:" << left << "j:" << j << endl;
                string tmp = "";
                for(int k = left; k <= j; ++k){
                    tmp.push_back(a[k]);
                }
                if(flag1){
                    ans = tmp;
                    flag1 = false;
                }
                if(tmp.size() < ans.size()  && flag1 == false){
                    ans = tmp;
                    c = left;
                }
                //cout << "tmp :" << tmp << endl;
                flag = true;
                j = left + 1;
                right = 0;
            }
        }
    //}
    cout << c << " " << ans << endl;
    return 0;
}
