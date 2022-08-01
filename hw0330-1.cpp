/*************************************************************************
	> File Name: hw0330-1.cpp
	> Author: Seottle
	> Mail: 874688169@qq.com
	> Created Time: Tue 28 Jun 2022 07:19:45 PM CST
 ************************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    while(cin >> n >> m){
    vector<int> hash(10010, 0);
    int idx = 0;
    while(m != 1){
        char x;
        cin >> x;
        if(x == 'A'){
            for(int i = 0; i < 10010; ++i){
                if(hash[i] != 4){
                    hash[i]++;
                    break;
                }
            }
        }else{
            for(int i = 0; i < 10010; ++i){
                if(hash[i] == 0){
                    hash[i] = 4;
                    break;
                }
            }
        }    
        m--;
    }
    char x;
    cin >> x;
    int i = 0;
        if(x == 'A'){
            for(i = 0; i < 10010; ++i){
                if(hash[i] != 4){
                    hash[i]++;
                    break;
                }
            }
            if(i + 1 > n) cout << "0 0" << endl;
            else cout << i + 1 << " "<< hash[i] << endl;
        }else{
            for(i = 0; i < 10010; ++i){
                if(hash[i] == 0){
                    hash[i] = 4;
                    break;
                }
            }
            if(i + 1 > n) cout << "0 0" << endl;
            else cout << i + 1 << " " << 1 << endl;
        }    
    }
    return 0;
}
