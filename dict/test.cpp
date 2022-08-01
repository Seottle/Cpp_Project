/*************************************************************************
	> File Name: test.cpp
	> Author: Seottle
	> Mail: 874688169@qq.com
	> Created Time: Thu 26 May 2022 11:06:47 AM CST
 ************************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

template<typename type, typename type2>
type Max(type a, type2 b){
    return a > b ? a : b;
}
int main(){

    cout << Max(5.9, 'a') << endl;
    return 0;
}
