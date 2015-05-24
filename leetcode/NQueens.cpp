// NQueens.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	vector<vector<string> > solveNQueens(int n) {
		vector<int> visit(n,-1);
		vector<int> ans;
		vector<vector<string> > ans1;
		//DFS
		dfs(visit,0,n,ans1);
		return ans1;
	}
	bool isValid(vector<int> &visit, int r){
		for(int i=0;i<r;++i){
			if(visit[i]==visit[r]||abs(visit[i]-visit[r])==(r-i))
				return false;
		}
		return true;
	}
	void dfs(vector<int > visit, int step, int deep, vector<vector<string>>& ret)	{
		if(step==deep){
			transF(visit,ret,deep);
			return;
		}
		for(int i=0;i<deep;i++){
			visit[step] = i;
			if(isValid(visit,step)){
				dfs(visit,step+1,deep,ret);
			}

		}
	}
	void printvec(vector<int>& vec){
		for_each(vec.begin(),vec.end(),[&](int i){cout<<i<<endl;});
	}
	void transF(vector<int>& vec, vector<vector<string>>& ans,int length){
		char Q = 'Q';
		string tP(length,'.');
		vector<string> tans;
		for(int i=0;i<length;i++){
			string tmp = tP;
			tmp[vec[i]]=Q;
			tans.push_back(tmp);
		}
		ans.push_back(tans);
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Solution test;
	test.solveNQueens(4);
	return 0;
}

