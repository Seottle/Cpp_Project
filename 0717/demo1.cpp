/*************************************************************************
	> File Name: demo1.cpp
	> Author: Seottle
	> Mail: 874688169@qq.com
	> Created Time: Sun 17 Jul 2022 05:00:59 PM CST
 ************************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    string str;
    while(cin >> str){
        vector<int> coins; 
        int cur_i = 0, pre = 0;
        while(str[cur_i] != ';'){
            if(str[cur_i] == ',') coins.push_back(atoi(str.substr(pre, cur_i - pre).c_str())), pre = cur_i + 1;
            cur_i++;
        }    
        coins.push_back(stoi(str.substr(pre, cur_i - pre)));
        int target = stoi(str.substr(cur_i + 1, str.length() - cur_i - 1));
        for(auto c : coins){
            cout << c << " ";
        }
        cout << endl << "target:" << target << endl;
        unordered_map<int, vector<vector<int>>> mp;
        mp[0] = {{}};
        vector<vector<int>> dp(coins.size() + 1, vector<int>(target + 1, 0));
        for(int i = 1; i <= coins.size(); ++i){
            for(int j = 1; j <= target; ++j){
                if(i >= coins[j]){
                if(dp[i - 1][j - coins[i]] + coins[i] > dp[i - 1][j]){
                    if(mp.find(i - coins[j]) != mp.end()){
                        for(vector<int> &cur_vec : mp[i - coins[j]]){
                            vector<int> tmp_vec = cur_vec;
                            tmp_vec.push_back(coins[j]);
                            mp[i - 1].push_back(tmp_vec);
                        }
                    }else dp[i][j] = dp[i - 1][j];
                }
                }else{
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        
        for(int i = 1; i <= target; ++i){
            cout << "mp[" << i << "]" << endl;
            for(int j = 0; j < mp[i].size(); ++j){
                for(int k = 0; k < mp[i][j].size(); ++k){
                    cout << mp[i][j][k] << " ";
                }
                cout << endl;
            }
        }
    }



    return 0;
}
