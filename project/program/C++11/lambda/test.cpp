/*************************************************************************
	> File Name: test.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 15 Aug 2022 10:08:21 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int main(){
    int b = 10;
    [=](int a){
        cout << a + b << endl;
    }(10);

    return 0;
}
