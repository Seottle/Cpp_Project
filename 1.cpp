/*************************************************************************
	> File Name: 1.cpp
	> Author: Seottle
	> Mail: 874688169@qq.com
	> Created Time: Tue 21 Jun 2022 06:21:26 PM CST
 ************************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[5] = {1, 2, 3, 4, 5};
    random_shuffle(a, a + 5);
    for(auto i : a){
        cout << i << " ";
    }
    vector<int> tmp = rand();
    return 0;
}
