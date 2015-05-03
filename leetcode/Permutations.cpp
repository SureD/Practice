// Permutations.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	vector<vector<int> > permute(vector<int> &num) {
		vector<vector<int> > ans;
		int step = num.size();
		if(step==0)
			return ans;
		dfs(0,step,num,ans);
		return ans;
	}
	void  dfs(int deep,int step,vector<int>& num, vector<vector<int>>& ans){
		if(step == deep){
			ans.push_back(num);
			return;
		}
		for(int i = deep;i<step;i++){
			swap(num,i,deep);
			dfs(deep+1,step,num,ans);
			swap(num,i,deep);
		}
	}
	void swap(vector<int>& num,int i, int j)
	{
		int t = num[i];
		num[i] = num[j];
		num[j] = t;
	}
	
};
int _tmain(int argc, _TCHAR* argv[])
{
	Solution test;
	vector<int> a;
	a.push_back(1);
	test.permute(a);
	return 0;
}

