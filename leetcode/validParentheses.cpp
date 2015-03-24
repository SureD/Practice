// validParentheses.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <stack>
using namespace std;
class Solution {
public:
	bool isValid(string s) {
		stack<char> s_brackets;
		if(s.length()<2) return false;
		for (int i=0;i<s.length();i++)
		{
			if (s[i]=='{'||s[i]=='('||s[i]=='[')
			{
				switch (s[i])
				{
				case '{':s_brackets.push('}'); break;
				case '(':s_brackets.push(')'); break;
				case '[':s_brackets.push(']'); break;
				}
			}
			else if(!s_brackets.empty()&&s_brackets.top()==s[i]){
				s_brackets.pop();
				continue;
			}else
				return false;
		}
		return s_brackets.size()==0;

	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Solution test;
	cout<<test.isValid("[])")<<endl;
	return 0;
}

