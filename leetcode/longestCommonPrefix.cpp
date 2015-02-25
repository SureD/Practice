// longestCommonPrefix.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
	string longestCommonPrefix(vector<string> &strs) {
		int len = strs.size();
		if (len==0) return "";
		string res = strs[0];
		int i,j=0;
		for (i=1;i<len;i++)
		{
			int k;
			j=res.size()>strs[i].size()?strs[i].size():res.size();
			for (k=0;k<j;k++)
			{
				if (res[k]!=strs[i][k])
					break;
			}
			res = res.substr(0,k);
		}
		return res;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

