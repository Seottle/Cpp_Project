/*************************************************************************
	> File Name: test.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 11 Aug 2022 05:51:23 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

//返回值类型后置
template<typename A , typename B>
auto add(A a, B b) -> decltype(a + b){
    return a + b;
}

int main(){
    int a = 1;
    int b = 2;
    auto c = add<int,int>(a, b);
    cout << "整型相加： " << c << endl;
    cout << "-----------" << endl;
    string s1 = "3";
    string s2 = "4";
    cout << "字符型相加：" << add<string, string>(s1, s2) << endl;
    cout << "-----------" << endl;
    cout << "默认的模板类型相加：" << add('a', 'b') << endl;
    return 0;
}
