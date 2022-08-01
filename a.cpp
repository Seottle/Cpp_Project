/*************************************************************************
	> File Name: a.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 26 Apr 2022 11:02:06 AM CST
 ************************************************************************/

#include<iostream>
//记住是用 "" 因为<>是在库文件中链接，""是在本文件中链接
//#include"b.h"/
using namespace std;
#include <unistd.h>
int main(){
    cout << "abc";
    sleep(3);
    cout << "def";  
    
    return 0;
}
