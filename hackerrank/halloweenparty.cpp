#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
	long long int a;
	cin>>a;
	if(a%2==0)
	{
        	cout<<(a/2)*(a/2)<<endl;
	}
	else
	{
		cout<<(a/2+1)*(a/2)<<endl;
	}
    }
}

