/*
 * 注意相等的情况……只输出一次，可以用stl中set
 */
#include<iostream>
using namespace std;
int main()
{
    int T;
    cin>>T;
    long long int n,a,b;
    while(T--){
        cin>>n>>a>>b;
        long long int t;
        t = a;
        if(a<b){
            a = b;
            b = t;
        }
        t = n-1;
        if(a==b){
            cout<<t*a<<endl;
           continue;
        }
        for(int i=0;i<n;i++)
            cout<<(t*b+i*(a-b))<<" ";
        cout<<endl;
    }
}
