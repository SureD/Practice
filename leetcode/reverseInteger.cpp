// reverseInteger.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int reverse(int x) {
		int flag=1;
		if (x<=-2147483648)
		{
			return 0;
		}
		if (x<0)
		{
			flag=-1;
			x = -x;
		}
		long int xx=0;
		while(x){
			xx = xx*10+x%10;
			x/=10;
		}
		if (xx>2147483647)
		{
			return 0;
		}
		return int(flag*xx);

	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	Solution test;
	int f = -2147483647;
	cout<<test.reverse(f)<<endl;
	return 0;
}

