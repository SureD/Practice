// 3Sum.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	vector<vector<int>> threeSum(vector<int> &num) {
		vector<vector<int>> res;
		if (num.size()<3)
			return res;
		sort(num.begin(),num.end(),[](const int& x,const int& y)->bool{return x<y;});
		for (int i=0;i<num.size();i++)
		{
			if (i!=0&&num[i]==num[i-1])
				continue;
			int p=i+1,q=num.size()-1;
			int sum=0;
			while(p<q){
				sum=num[i]+num[p]+num[q];
					if (sum==0)
					{
						vector<int> temp;
						temp.push_back(num[i]);
						temp.push_back(num[p]);
						temp.push_back(num[q]);
						res.push_back(temp);
						while (++p<q&&num[p-1]==num[p]){}
						while (p<--q&&num[q]==num[q+1]){}
						
					}
					else if (sum>0)
						q--;
					else
						p++;
			}
		}
		return res;
		

	}

};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

