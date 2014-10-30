#include<iostream>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--){
        long long int n,c,t;
        int ans=0;
        cin>>n;
        t = n;
        while(n){
            c = n%10;
            n = n/10;
            c = c==0?t-1:c;
            if(t%c==0)
                ans++;
        }
        cout<<ans<<endl;
    }
	return 0;
}
