// romanToInteger.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <map>
using namespace std;
class Solution {
public:
	int romanToInt(string s) {
		map<char,int> dct;
		dct['I'] = 1;
		dct['V'] = 5;
		dct['X'] = 10;
		dct['L'] = 50;
		dct['C'] = 100;
		dct['D'] = 500;
		dct['M'] = 1000;
		int ans = 0;
		int i=0,j=0;
		for (i=0;i<s.length();i++)
		{
			j=i+1;
			if (j<s.length()&&dct[s[j]]>dct[s[i]])
			{
				ans+= dct[s[j]]-dct[s[i]];
				i=j;
			}else
				ans+=dct[s[i]];
		}
		return ans;

	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

