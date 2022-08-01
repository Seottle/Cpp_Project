/*************************************************************************
	> File Name: printf.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 22 Apr 2022 10:04:28 AM CST
 ************************************************************************/

#include<iostream>
#include<bits/stdc++.h>
#include<stdarg.h>

using namespace std;
//利用putchar()来实现输出
//... 代表 可变参数
int my_printf(const char *frm, ...){
    int cnt = 0; // 成功打印出来的字符个数
    va_list arg;    
    va_start(arg, frm);
    #define PUTC(a) putchar(a), cnt++
    for(int i = 0; i < strlen(frm); ++i){
        switch(frm[i]){
            case '%':{
                switch(frm[++i]){
                    case '%':PUTC(frm[i]);break;
                    case 'd':{
                        int x = va_arg(arg, int);
                        if(x < 0) {
                            PUTC('-');
                            x = -x;
                        }
                        string temp = to_string(x);
                        for(auto i : temp){
                            PUTC(i);
                        }    
                    }
                }break;
            } break;
            default:PUTC(frm[i]);break;
        }   
    }
    #undef PUTC
    return cnt;
}

int main(){
    int a;
    printf("Hello zxt\n");
    my_printf("Hello zxt\n");
    while(cin >> a){
        printf("int (a) = %d\n", a);
        my_printf("int (a) = %d\n", a);
    }
    
    return 0;
}
