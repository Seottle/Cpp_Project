/*************************************************************************
	> File Name: compute_sqrt2.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 03 Aug 2022 03:31:05 PM CST
 ************************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define procesion 1e-10
double m(double x){
    return x * x;
}
double Sqrt_x(double n){
    double left = 1, right = n, mid;
    while(right - left > procesion){
        mid = (right + left) / 2;
        if(m(mid) > n){
            right = mid;
        }else{
            left = mid;
        }
    }
    return mid;
}

int main(){
    double n;
    cin >> n;
    cout << Sqrt_x(n) << endl;
    return 0;
}
