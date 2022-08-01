/*************************************************************************
	> File Name: test1.cpp
	> Author: Seottle
	> Mail: 874688169@qq.com
	> Created Time: Wed 20 Jul 2022 07:25:04 PM CST
 ************************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
string to_binary(int n){
    string str = "";
    while(n){
        str += to_string(n % 2);
        n /= 2;
    }
    reverse(str.begin(), str.end());
    return str;
}
int count(int n){
    int cnt = 0;
    while(n){
        if(n % 2 == 1) cnt++;
        n /= 2;
    }
    return cnt;
}
int main(){
    int n;
    while(cin >> n){
        if(n == -1 || n > pow(10, 10)) {
            cout << -1 << endl;
            break;
        }
        //cout << to_binary(n) << ": 1的个数"<< count(n) <<endl;
        int ans = 0;
        for(int i = 1; i <= n; ++i){
            string tmp = to_binary(i);
            int m = tmp.size();
            int flag = 1;
            if(count(i) == 2){ // 1的个数为2个时
                //cout << "i = " << i << endl;
                if(m % 2 == 0){
                    if(tmp[0] == '1' && tmp[m/2] == '1'){
                        cout << i << "的二进制是:"<< tmp << endl;
                        flag = 0;
                        ans++;
                    }
                }
            }
            if(flag && m % 2 == 0 && i + 1 == pow(2, m)) {  //偶数的情况下 全1时     
                cout << i << "的二进制是:"<< tmp << endl;
                ans++;
            }
        }
        cout << ans << endl;
   }
    return 0;
}


