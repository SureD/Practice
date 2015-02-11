// longestSubstringWithoutRepeatingCharacters.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
class Solution{
public:
	void findRepeatCharAndCut(string& str,char key)
	{
		int i=0;
		while(str[i]!=key&&i<str.size())
		{
			i++;
		}
		if (i<str.size())
		{
			str = str.substr(i+1,str.size()-i-1);
		}
		
	}
	int lengthOfLongestSubstring(string s) {
		int _max=1,t_max=1;
		size_t _size = s.size();
		if (_size==0)
		{
			return 0;
		}
		string maxString;
		maxString.reserve(_size);
		maxString.push_back(s[0]);
		for (int i=1;i<_size;i++)
		{
			findRepeatCharAndCut(maxString,s[i]);
			maxString.push_back(s[i]);
			t_max = maxString.size();
			_max = max(_max,t_max);
		}
		return _max;

	}
	int lengthOfLongestSubstringByMap(string s)
	{
		const int MAX_CHARS = 256;
		int m[MAX_CHARS];
		memset(m,-1,sizeof(m));
		int maxLen = 0;
		int lastRepeat  = -1;
		for (int i=0;i<s.size();i++)
		{
			if (m[s[i]]!=-1&&lastRepeat<m[s[i]])
			{
				lastRepeat = m[s[i]];
			}
			if(i-lastRepeat>maxLen)
				maxLen = i-lastRepeat;
			m[s[i]] = i;
		}
		return maxLen;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	Solution test;
	string a = "abcdbefghi";
	cout<<test.lengthOfLongestSubstring(a)<<endl;
	cout<<test.lengthOfLongestSubstringByMap(a)<<endl;
	return 0;
}

