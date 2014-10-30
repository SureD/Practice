/*
 * O(n)  记录每个字母出现的次数即可
 */
#include<iostream>
#include<string>
using namespace std;
int main()
{
    int sum=0;
    string a;
    cin>>a;
    int c[26];
    for(int i=0;i<26;i++)
        c[i]=0;
    for(int i=0;i<a.length();i++)
        c[a[i]-'a']++;
    for(int i=0;i<26;i++)
        sum+=(c[i]%2);
    if(sum>=2)
        cout<<"NO"<<endl;
    else
         cout<<"YES"<<endl;

}

