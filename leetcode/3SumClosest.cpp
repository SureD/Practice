// 3SumClosest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	int threeSumClosest(vector<int> &num, int target) {
		int res = 0;
		int bias = INT_MIN-2;
		sort(num.begin(),num.end(),[](const int &a,const int &b)->bool{return a<b;});
		int len = num.size();
		for (int i=0;i<len;i++)
		{
			if (i>0&&num[i-1]==num[i])
				continue;
			int p=i+1,q=len-1,sum=0,t_bias=0;
			while (p<q)
			{
				sum = num[p]+num[q]+num[i];
				if (sum==target)
					return target;
				else {
					t_bias = sum-target;
					if (t_bias<0)
					{
						bias = abs(bias)>abs(t_bias)?t_bias:bias;
						p++;
					}else {
						bias = abs(bias)>abs(t_bias)?t_bias:bias;
						q--;
					}
				}

			}
		}
		return (target+bias);
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Solution test;
	vector<int> a;
	a.push_back(-1);
	a.push_back(2);
	a.push_back(1);
	a.push_back(-4);
	cout<<test.threeSumClosest(a,1)<<endl;
	return 0;
}

