#include<cmath>
#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int length,n,in,out,temp;
    cin>>length>>n;
    vector<int> widths;
    vector<int> ans;
    vector<int>::iterator iter;
    while(length--){
        cin>>temp;
        widths.push_back(temp);
    }
    temp = n;
    while(n--){
        int min;
        cin>>in>>out;
        min = widths[out];
        for(int i=in;i<out;i++){
            min = widths[i]>min?min:widths[i];
            if (min == 1)
                break;
        }
        ans.push_back(min);
    }
    for(iter = ans.begin();iter!=ans.end();iter++)
        cout<<*iter<<endl;

    return 0;
}
