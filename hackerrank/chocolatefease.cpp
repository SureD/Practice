#include<iostream>
using namespace std;
int main()
{
    int co;
    cin>>co;
    int n,c,m;
    while(co--){
        cin>>n>>c>>m;
        int tempa,ans=0;
        tempa = n/c;
        ans+=tempa;
        while(tempa>=m){
            ans++;
            tempa-=c;
            tempa++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
