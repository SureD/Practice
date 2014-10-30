#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n,sum;
    cin>>n;
    sum = n;
    vector<int> s;
    vector<int>::iterator itera,iterb;
    while(n--){
        int t;
        cin>>t;
        s.push_back(t);
    }
    sort(s.begin(),s.end());
    cout<<sum<<endl;
    itera = s.begin();
    iterb = itera;
    while(itera!=s.end()){
        int min,t;
        min = *itera;
        while(iterb!=s.end()){
            ++iterb;
            if(min<*iterb)
                break;       
        }
        t = iterb-itera;
        sum-=t;
        if(sum!=0)
        cout<<sum<<endl;
        itera = iterb;
    }
}
