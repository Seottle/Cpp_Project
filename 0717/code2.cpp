/*************************************************************************
	> File Name: code2.cpp
	> Author: Seottle
	> Mail: 874688169@qq.com
	> Created Time: Mon 18 Jul 2022 10:33:40 AM CST
 ************************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//set<vector<int>> ans;
vector<vector<int>> ans;
vector<int> path;
void dfs(vector<int>& coins, int idx, int target){
    if(target < 0) return;
    if(target == 0){
        ans.push_back(path);
        //ans.insert(path);
        return;
    }
    for(int i = idx; i < coins.size(); ++i){
        if(i > 0 && coins[i] == coins[i - 1]) continue;
        path.push_back(coins[i]);
        dfs(coins, i + 1, target - coins[i]);
        path.pop_back();
    }
}

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
    
        dfs(coins, 0, target);
        for(vector<int> a : ans){
            for(int x : a){
                cout << x <<" ";
            }
            cout << endl;
        }
        ans.clear();
        path.clear();
    }
    return 0;
}
