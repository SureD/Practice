// regularExpressionMatching.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
class Solution {
public:
	bool isMatch(const char *s, const char *p) {
		if (*p=='\0') return *s=='\0';
		// next char is not '*'
		if (*(p+1)!='*')
		{
			return(*p==*s||(*p=='.'&&*s!='\0'))&&isMatch(s+1,p+1);
		}
		// next char is '*'
		while((*p==*s)||(*p=='.'&&*s!='\0'))
		{
			if (isMatch(s,p+2)) return true;
			s++;
		}
		return isMatch(s,p+2);
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

