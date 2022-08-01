/*************************************************************************
    > File Name: code1.cpp
    > Author: Seottle
    > Mail: 874688169@qq.com
    > Created Time: Mon 18 Jul 2022 09:58:09 AM CST
 ************************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int amount;
    while(cin >> amount){
        int coins[3] = {1, 4, 5};
        
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        vector<vector<int>> cnt(amount + 1, vector<int>(3, 0));

        for(int i = 1; i <= amount; ++i){
            int change = -1;
            vector<int> tmp;
            for(int j = 0; j < 3; ++j){
                int coin = coins[j];
                if(i >= coin){
                    if(dp[i] > dp[i - coin] + 1){
                        dp[i] = dp[i - coin] + 1;
                        change = j;
                    }
                }
            }
            cnt[i] = cnt[i - coins[change]];
            cnt[i][change] = cnt[i - coins[change]][change] + 1;
        }
        /*
        for(vector<int> c : cnt){
            cout << "1   4   5" << endl;
            for(int x : c){
                cout << "[" << x << "] ";
            }
            cout << endl;
        }
        */
        for(int i = 0 ; i < 3; ++i){
            if(i < 2) cout << cnt[amount][i] << ",";
            else cout << cnt[amount][i] << endl;
        }
    }

    return 0;
}
