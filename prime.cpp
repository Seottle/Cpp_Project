/*************************************************************************
	> File Name: prime.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 23 Apr 2022 05:06:39 PM CST
 ************************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int MAXN = 2000000;
vector<int> prime(MAXN, 0);
//线性筛法
void init_prime(){
    for(int i = 2; i <= MAXN; ++i){
        if(prime[i] == 0) {
            prime[++prime[0]] = i;
        }
        for(int j = 1; j <= prime[0]; ++j){
            if(prime[j] * i > MAXN) break;
            prime[prime[j] * i] = 1;
            if(i % prime[j] == 0) break;
        }
    }
    return ;
}
int main(){
    init_prime();
    long long sum = 0;
    for(int i = 1; i <= prime[0]; ++i){
        sum += prime[i];
    }
    cout << "sum = " << sum << endl;
    return 0;
}

