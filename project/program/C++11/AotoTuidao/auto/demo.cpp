/*************************************************************************
	> File Name: demo.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 11 Aug 2022 05:08:41 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class A{
    public:
    static int get(){
        cout << "int A: " << endl;
        return 10;
    }
};
class B{
    public:
    static string get(){
        cout << "string B " << endl;
        return "zxt";
    }
};
template<class C>
void fun(){
    auto ret = C::get();
    cout << ret << endl;
}
int main(){
    fun<A>();
    fun<B>();
    return 0;
}
