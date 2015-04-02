// LongestValidParentheses.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <stack>
using namespace std;
class Solution {
public:
	int longestValidParentheses(string s) {
		if (s.empty())
			return 0;
		int len = s.length();
		int * mp = new int[len];
		memset(mp,0,sizeof(int)*len);
		stack<int> lefts;
		for (int i=0;i<len;i++)
		{
			switch (s[i])
			{
			case '(':
					lefts.push(i);
					break;
			case ')':
					if (!lefts.empty())
					{
						mp[i] = 1;
						mp[lefts.top()] = 1;
						lefts.pop();
					}
					break;
			}
		}
		int ans = 0;
		int count = 0;
		for (int i=0;i<len-1;i++)
		{
			if (mp[i]==0&&mp[i+1]==1)
			{
				ans = ans>count?ans:count;
				count = 0;
				continue;
			}
			if (mp[i]==1)
			{
				count++;
			}
		}
		if (mp[len-1])
		{
			count++;
		}
		return max(ans,count);
	}
};
int main()
{
	string test;
	test = "()";
	Solution tt;
	cout<<tt.longestValidParentheses(test)<<endl;
}