#include<iostream>
#include<string>
using namespace std;

int main()
{
    int n;
    cin>>n;
    while(n--){
        int count = 0,b,e;
        string a;
        cin>>a;
        b = 0;
        e = a.length()-1;
            while(b<e){
            int temp;
            temp=a[e]-a[b];
            temp = temp>0?temp:-temp;
            count+=temp;
            e--;
            b++;
        }
        cout<<count<<endl;
    }

    return 0;
}
