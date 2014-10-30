#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
    string a;
    int count = 0;
    string::iterator iter;
    cin>>a;
    sort(a.begin(),a.end());
    iter = a.begin();
    while(iter!=a.end()){
        if(*iter==*(iter+1))
            iter+=2;
        else
        {
            count++;
            iter++;
        }
    }
    if(count==1||count==0)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
        
    return 0;
    
}
