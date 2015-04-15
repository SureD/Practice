// CombinationSumII.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution {
public:
	vector<vector<int> > combinationSum2(vector<int> &num, int target) {
		ret.clear();
		if(num.empty())
			return ret;
		vector<int> ans;
		ans.clear();
		sort(num.begin(),num.end());
		dfs(num,ans,target,0);
		return ret;
	}
	void dfs(vector<int>& num, vector<int> ans,int target,int left){
		//if(left>0&&left<num.size()&&num[left]==num[left-1])
		//	return;
		if(target==0){
			ret.push_back(ans);
			return;
		}
		if(left>num.size())
			return;
	
		for(int i=left;i<num.size();){
		
			if(num[i]>target||i>=num.size())
				break;
			ans.push_back(num[i]);
			dfs(num,ans,target-num[i],i+1);
			ans.pop_back();
			int j=i+1;
			while(j<num.size()&&num[j]==num[i])
				j++;
			i = j;

		}
		return;

	}
private:
	vector<vector<int> > ret;
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

