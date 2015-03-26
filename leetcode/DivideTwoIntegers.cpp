// DivideTwoIntegers.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
class Solution {
public:
	int divide(int dividend, int divisor) {
		if (dividend==0)
		{
			return 0;
		}
		if (divisor==0)
		{
			return INT_MAX;
		}
		INT_MIN;
		int flag=1;
		flag = dividend>0?flag:(-flag);
		flag = divisor>0?flag:(-flag);
		int ans = 0;
		int i = 1;
		long long x,y,base;
		x = dividend;y = divisor;
		x = abs(x);
		y = abs(y);
		base = y;
		while (x>=y)
		{
			base = y;
			for (int i=0;x>=base;i++)
			{
				x-=base;
				base<<=1;
				ans+=1LL<<i;
			}
		}
		if (ans==(-INT_MIN)&&flag==1)
		{
			return INT_MAX;
		}
		return flag*ans;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Solution test;
	cout<<test.divide(-2147483647,-1)<<endl;
	return 0;
}

