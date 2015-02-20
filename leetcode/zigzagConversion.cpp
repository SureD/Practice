// zigzagConversion.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include "string"
using namespace std;
class Solution {
public:
	string convert(string s, int nRows) {
		string ret;
		size_t _length = s.length();
		if(_length==0||nRows<2) return s;
		int lag = 2*nRows-2;
		for (int i=0;i<nRows;i++)
		{
			for (int j=i;j<_length;j+=lag)
			{
				ret+=s[j];
				if (i>0&&i<nRows-1)
				{
					int t = j+lag-2*i;
					if (t<_length)
					{
						ret+=s[t];
					}
				}
			}
		}
		return ret;
		
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

