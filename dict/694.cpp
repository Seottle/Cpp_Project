/*************************************************************************
	> File Name: 694.cpp
	> Author: Seottle
	> Mail: 874688169@qq.com
	> Created Time: Wed 25 May 2022 04:17:44 PM CST
 ************************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& grid, int i, int j, int dir, string& str){
    int row = grid.size(), col = grid[0].size();
    if(i < 0 || j < 0 || i >= row || j >= col)
        return;
    if(grid[i][j] == 0)
        return;
    grid[i][j] = 0;
    //in:
    str += to_string(dir) + ',';
    dfs(grid, i - 1, j, 1, str);
    dfs(grid, i + 1, j, 2, str);
    dfs(grid, i, j - 1, 3, str);
    dfs(grid, i, j + 1, 4, str);
    //out
    str += to_string(-dir) + ','; 
}
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> grid[i][j];
        }
    }
    
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cout << grid[i][j] << "---";
        }
        cout << endl;
    }
    
    set<string> S;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(grid[i][j] == 1){
                string tmp = "";
                dfs(grid, i, j, 666, tmp);
                cout << "岛屿"<< i << " " << j << " :"<< tmp << endl;
                S.insert(tmp);
            }
        }
    }
    cout << "ans = " << S.size() << endl;

    return 0;
}
