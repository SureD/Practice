/*
*  负二进制的转换及加法计算
*  利用了取余法求取当前位置上的数
*================================================
*          
*            2---->n    n+1            3 
*	-2|——————                  -2|--------
*         |  -5          ====>       | -5
*         --------                   ---------
*            -1 ---->m   m+2            1 
*/
#include<iostream>
#include<string>
#include<cassert>
using namespace std;
string num2neg(int n){
    string c;
    while(n!=0){
        int m;
        m = n%2; //余数
        n = n/(-2);//除数
        if(m<0)   //余数小于0
        {
            m+=2; //将余数+2相当于把除数加了1
            n++;
        }
        c = char(m+'0')+c;
    }
    return c;
}
string negsum(string &a,string &b)
{
    string c;
    int la,lb,f;
    la = a.length()-1;
    lb = b.length()-1;
    f = 0;
    int ts;
    while(la>=0||lb>=0||f){
        int pa = la>=0?a[la]-'0':0;
        int pb = lb>=0?b[lb]-'0':0;
        ts = pa+pb+f;
        switch(ts){
            case -1:{
                f = 1;
                c = "1" + c;
                    };break;
            case 0: case 1:{
                f = 0;
                c = char(ts+'0')+c;
                     };break;
            case 2: case 3:{
                f = -1;
                c = char(ts-2+'0')+c;
                           };break;
            default:
            //    error("Error");
                exit(-1);
                break;
                
        }
        la--;
        lb--;
    }
    return c;

}
//进位例如若11与11相加，那么1+1=2 相当于 (-2)^i+(-2)^i=(-1)*(-2)^(i+1)相当于向高位进-1
//case为-1时如(01+01)，相当于将当前位置为1并且向前进位，相当于(-2)^i*2 = (-2)^(i+1)+(-2)^(i+2);
int main()
{
    string a;
    a = num2neg(-2);
    cout<<a<<endl;
    return 0;
}
