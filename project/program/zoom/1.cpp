/*************************************************************************
	> File Name: 1.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 14 Aug 2022 07:46:26 PM CST
 ************************************************************************/

#include<iostream>
#include <bits/stdc++.h>
using namespace std;

struct tasks{
    int w;
    int s;
    int e;
};

int main(){
    int n, m;
    cin >> n >> m;
    vector<tasks> task(n);
    for(int i = 0; i < n; ++i){
        cin >> task[i].w >> task[i].s >> task[i].e;
    }
    sort(task.begin(), task.end(), [](tasks& a, tasks& b){
        if(a.s != b.s){
            return a.s < b.s;
        }else{
            return a.e > b.e;
        }
    });
    
    int end = task[0].e;
    int maxw = task[0].w;
    int index = 0;
    for(int i = 1; i < n; ++i){
        if(task[i].s > end){
            end = task[i].e;
            if(task[i].w > maxw){
                maxw = task[i].w;
                index = i;
            }
        }
    }
    cout << maxw << index << endl;
    return 0;
}
