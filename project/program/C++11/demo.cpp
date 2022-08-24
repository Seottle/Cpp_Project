/*************************************************************************
	> File Name: demo.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 11 Aug 2022 09:11:15 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int main(){

    
    cout << (sizeof(int) == 4? 32:16) << endl;
    cout << endl;
    unsigned int a = ~0; //取反
    cout << (a > 65536 ? 32 : 16) << endl;
    return 0;
}
