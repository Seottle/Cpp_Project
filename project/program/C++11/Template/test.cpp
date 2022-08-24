/*************************************************************************
	> File Name: test.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 11 Aug 2022 08:47:35 PM CST
 ************************************************************************/

#include<iostream>
#include <bits/stdc++.h>
using namespace std;

template<typename T>
class container{
    public:
    void print(T& t){
        /*
        auto x = t.begin();
        for(; x!=t.end(); ++x){
            cout << x->first << ",  " << x->second << endl;
        }
        */
        for(auto& it : t){
            cout << it.first << ",  " << it.second << endl;
        }
    }
    
};

int main(){
    map<int, string> mp{make_pair(1, "zxt")};
    mp[2] = "csj"; 
    container<map<int, string>> c;
    c.print(mp);
    return 0;
}
