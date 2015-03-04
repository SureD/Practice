// 4Sum.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	vector<vector<int> > fourSum(vector<int> &num, int target) {
		vector<vector<int>> res;
		if (num.size()<4)
			return res;
		sort(num.begin(),num.end(),[](const int &x,const int&y)->bool{return x<y;});
		for (int i=0;i<num.size();i++)
		{
			if (i>0&&num[i-1]==num[i])
				continue;
			int targetb = target-num[i];
			for (int j=i+1;j<num.size();j++)
			{
				if (j>i+1&&num[j]==num[j-1])
					continue;
				int p = j+1, q=num.size()-1;
				while (p<q)
				{
					if (num[j]+num[p]+num[q]==targetb)
					{
						vector<int> temp;
						temp.push_back(num[i]);
						temp.push_back(num[j]);
						temp.push_back(num[p]);
						temp.push_back(num[q]);
						res.push_back(temp);
						while(++p<num.size()&&num[p]==num[p-1]){}
						while (--q>j&&num[q]==num[q+1]){}
					}else if (num[j]+num[p]+num[q]<targetb)
					{
						p++;
					}else
						q--;
				}
			}
		}
		return res;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	
	return 0;
}

