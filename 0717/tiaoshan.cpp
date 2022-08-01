/*************************************************************************
	> File Name: tiaoshan.cpp
	> Author: Seottle
	> Mail: 874688169@qq.com
	> Created Time: Mon 18 Jul 2022 10:56:01 AM CST
 ************************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class UF{
public:
    vector<int> parent;
    vector<int> size;
    int count;
    int NUM;
    UF(int n){
        parent.resize(n + 1);
        size.resize(n + 1);
        for(int i = 1; i <= n; ++i){
            parent[i] = i;
            size[i] = 1;
        }
        count = 0;
        NUM = n;
    }

    void print(int n){
        for(int i = 1; i <= n; ++i){
            cout << "玩家 : " << i << " 跟随: " << parent[i] << " 团队人数:" << size[i] << endl;
        }    
    
    }

    void Union(int a, int b){
        int rootA = find(a);//玩家A所在的团队
        int rootB = find(b);//玩家B所在的团队
        if(rootA == rootB) return;
        //A 跟随 B 时，要把A的整个团队都跟随 B
        for(int i = 1; i <= NUM; ++i){
            int tmp = find(i);
            if(tmp == rootA){
                parent[i] = rootB;
            }
        }
        parent[rootA] = rootB;
        size[rootB] += size[rootA];
        count--;
    }
    
    int find(int q){
        if(parent[q] != q){
            parent[q] = find(parent[q]);
        }
        return parent[q];
    }
    //取消跟随
    void Del_Union(int a){
        int rootA = find(a);
        parent[a] = a;
        size[a] = 1;
        size[rootA] -= 1;
        count++;
    }
};

int main(){
    int n, k;
    while(cin >> n >> k){
        UF* uf = new UF(n);
        // uf->print(n);
        while(k--){
            int A, B;
            cin >> A >> B;
            if(B > 0){
                if(A == B) break;
                else{
                    uf->Union(A, B);
                    //uf->print(n);
                }
            }else{
                uf->Del_Union(A);
                //uf->print(n);
            }
        }
        int ans = 0; 
        for(int i = 1; i <= n; ++i){
            ans = max(ans, uf->size[i]);
        }
        uf->print(n);
        cout << "ret:"<< ans << endl; 
    }


    return 0;
}
