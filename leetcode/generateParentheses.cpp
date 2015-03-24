// generateParentheses.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
	void dfs(string str,int left,int right,vector<string>& res)
	{
		if (left>right) return;
		if (left==0&&right==0)
		{
			res.push_back(str);
		}
		if (left>0)
		{
			dfs(str+"(",left-1,right,res);
		}
		if(right>0)
			dfs(str+")",left,right-1,res);

	}
	vector<string> generateParenthesis(int n) {
		vector<string> res;
		string ans;
		dfs(ans,n,n,res);
		return res;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

