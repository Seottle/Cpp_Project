/*************************************************************************
	> File Name: HW1.2.cpp
	> Author: Seottle
	> Mail: 874688169@qq.com
	> Created Time: Thu 23 Jun 2022 10:36:27 AM CST
 ************************************************************************/
#include <stdio.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
        int n;
   
        cin >> n;
       
        int nums[n];
        for(int i = 0; i < n; ++i){
            cin >> nums[i];
        }
        for(int i = 0; i < n; ++i){
            cout << nums[i];
        }
        int ans = 0;
        for(int i = 0; i < n; ++i){
            int step = nums[i];//最大步数
            if(step == 0) {
                cout << -1 << endl;//走不到惹
                break;
            }
            int maxstep = INT_MIN;
            int idx;
            for(int j = 1; j <= step; ++j){
                if(nums[i + j] > maxstep){
                    maxstep = nums[i + j];
                    idx = j;
                } 
            }
            ans++;
            if(idx == n - 1) break;
            i = idx;
        }
        cout << ans << endl;
   
    
    return 0;
}
