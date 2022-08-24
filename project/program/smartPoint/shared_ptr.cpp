#include<iostream>
#include<bits/stdc++.h>
using namespace std;
template<typename T>
class sharedPtr{
private:
    T* myptr;   //模板指针T，不同shared_ptr指向同一个对象
    size_t* mycount; //引用计数，不同shared_ptr指向同一引用计数
    //size_t类型是一个类型定义，通常将一些无符号的整形定义为size_t,在不同的机器中定义不同
public:
    sharedPtr(T* p=nullptr) :  myptr(p), mycount(new size_t(1)){
        if(myptr != nullptr){
            cout << "first construct -->";
            cout << "info:" << *myptr << endl;
        }
    }
    sharedPtr(const sharedPtr& p){ //拷贝构造函数
        myptr = p.myptr;
        mycount = p.mycount;
        (*mycount)++;
        cout << "copy = " << *mycount << endl;
    }
    //赋值函数 = 
    //赋值函数，为什么返回类型是引用 要判断是不是在同一块内存 回答：返回值是引用才可以连续进行赋值；形参是引用，避免重复调用拷贝构造函数
    sharedPtr& operator=(const sharedPtr& other){ 
        if(this != &other){ //如果是同一个对象不进行实例操作
            myptr = other.myptr;
            mycount = other.mycount;
            (*mycount)++;
        }
        return *this;
    }
    ~sharedPtr(){
        *mycount--;
        if(*mycount == 0){
            delete mycount;
            delete myptr;
            cout << "destroy all" << endl;
        }
    }
    T& operator*(){
        return *myptr;
    }
    T* operator->(){
        return myptr;
    }
    int use_count() {//获取引用计数
        return *mycount;
    }
};
int main(){
    sharedPtr<string> a(new string("a"));
    //cout << "a = " << *a << endl;
    sharedPtr<string> b = a;
    cout << "b = " << *b << endl;
    cout << endl << "自带的智能指针 " << endl;
    shared_ptr<int> p1(new int(1));
    cout << *p1 << endl;
    cout << "p1 cnt = " <<p1.use_count() << endl;
    shared_ptr<string> p2 = make_shared<string>();
    cout << "p2 cnt = " <<p2.use_count() << endl;
    shared_ptr<string> p3 = p2;
    cout << "p3 cnt = " <<p2.use_count() << endl;
    return 0;
}



