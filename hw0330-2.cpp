/*************************************************************************
	> File Name: hw0330-2.cpp
	> Author: Seottle
	> Mail: 874688169@qq.com
	> Created Time: Wed 29 Jun 2022 09:33:14 AM CST
 ************************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int num = 0;
int min_step = INT_MAX;
int m, n;
void dfs(int startx, int starty, vector<vector<int>>& graph, vector<vector<int>> memo, int endx, int endy, int step){
    if(startx < 0 || startx > m - 1 || starty < 0 || starty > n - 1){
        return;
    }
    if(graph[startx][starty] == 1) return;//障碍物
    if(memo[startx][starty] == 1) return;
    if(startx == endx && starty == endy){
        if(step == min_step){
            num++;
        }
        if(step < min_step){
            min_step = step;
            num = 1;
        }
        return;
    }
    memo[startx][starty] = 1;
    dfs(startx + 1, starty, graph, memo, endx, endy, step + 1);    
    dfs(startx - 1, starty, graph, memo, endx, endy, step + 1);    
    dfs(startx, starty + 1, graph, memo, endx, endy, step + 1);    
    dfs(startx, starty - 1, graph, memo, endx, endy, step + 1);    
    memo[startx][starty] = 0;
}
int main(){
    cin >> m >> n;
    vector<vector<int>> graph(m, vector<int>(n, 0));
    int startx, starty;
    cin >> startx >> starty;
    int endx, endy;
    cin >> endx >> endy;
    int p;
    cin >> p;
    vector<vector<int>> memo(m, vector<int>(n, 0));
    while(p--){
        int a, b;
        cin >> a >> b;
        graph[a][b] = 1;
    }
    dfs(startx, starty, graph, memo, endx, endy, 0);
    cout << "num:" << num << "min_step" << min_step << endl;
    return 0;
}
