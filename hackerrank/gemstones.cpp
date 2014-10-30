#include<iostream>
#include<string>
using namespace std;
int main()
{
    int n,count,ans=0;
    cin>>n;
    count=n;
    int c[26]={0};
    while(n--)
    {
        string a;
        cin>>a;
        int t[26]={0};
        for(int i=0;i<a.length();i++)
        {
                t[a[i]-'a']=1;
        }
        for(int i=0;i<26;i++)
            c[i]+=t[i];
    }
    for(int i=0;i<26;i++)
        if(c[i]==count)
            ans++;
    cout<<ans<<endl;
}
