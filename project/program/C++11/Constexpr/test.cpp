/*************************************************************************
	> File Name: test.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 11 Aug 2022 03:29:43 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

constexpr int fun(int c){
    int a = 1;
    for(int i = 0; i < c; ++i){
        a++;
    }
    return a;
}

int main(){
    int c = 2;
    int b = fun(c);
    cout << "b = " << b << endl;
    return 0;
}
