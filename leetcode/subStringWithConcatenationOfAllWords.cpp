// subStringWithConcatenationOfAllWords.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
	vector<int> findSubstring(string S, vector<string> &L) {
		vector<int> result;
		if (S.length()==0||L.size()==0)
		{
			return result;
		}
		map<string,int> expect;
		int i,j;
		for ( i=0;i<L.size();i++)
		{
			if (expect.find(L[i])!=expect.end())
			{
				expect[L[i]]++;
			}else
				expect[L[i]] = 1;
		}
		int n = S.size();
		int step = L[0].size();
		for (i = 0; i < n; i++)
		{
			map<string,int> actual;
			int count = 0;
			int winLeft = i;
			for (j = i;j<=(n-step);j+=step)
			{
				string temp = S.substr(j,step);
				if (expect.find(temp)==expect.end())
				{
					actual.clear();
					winLeft = j+step;
					count = 0;
					continue;
				}
				count++;
				if (actual.find(temp)==actual.end())
				{
					actual[temp]=1;
				}else
					actual[temp]++;

				if (actual[temp]>expect[temp])
				{
					string tmp ;
					do 
					{
						tmp = S.substr(winLeft,step);
						actual[tmp]--;
						winLeft+=step;
						count--;

					} while (tmp!=temp);
				}
				if (count==L.size())
				{
					string tmp;
					result.push_back(winLeft);
					tmp = S.substr(winLeft,step);
					actual[tmp]--;
					winLeft+=step;
					count--;
					
				}
			}

		}
		return result;

	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Solution test;
	vector<string> L;
	L.push_back("mississippis");
	string S=  "mississippi";
	test.findSubstring(S,L);
	return 0;
}

