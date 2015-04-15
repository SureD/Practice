// CombinationSum.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
		vector<int> ans;
		ret.clear();
		ans.clear();
		sort(candidates.begin(),candidates.end());
		dfs(ans,candidates,target,0);
		return ret;
	}
	bool dfs(vector<int>& ans,vector<int> &candidates,int target,int left){
		if(target==0){
			ret.push_back(ans);
			return true;
		}
		if(left>=candidates.size())
			return false;
		if(candidates[left]>target)
			return false;
		for(int i=left;i<candidates.size();i++){
			if(candidates[i]>target)
				break;
			ans.push_back(candidates[i]);
			dfs(ans,candidates,target-candidates[i],i);
			ans.pop_back();
		}
		return false;
	}
private:
	vector<vector<int> > ret;

};


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

