// Palindrome Number.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
class Solution {
public:
	bool isPalindrome(int x) {
		if (x>INT_MAX||x<0)
		{
			return 0;
		}
		long renum = 0;
		int y = x;
		while(y)
		{
			renum = renum*10+y%10;
			y/=10;
			if (renum>INT_MAX)
				return 0;
		}
		return x==renum;

	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	Solution test;
	cout<<test.isPalindrome(1233213)<<endl;
	return 0;
}

