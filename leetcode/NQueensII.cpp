// NQueensII.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
	int totalNQueens(int n) {
		vector<int> visit;
		int ans=0;
		dfs(visit,-1,n,ans);
		return ans;
	}
	bool isValid(vector<int>& v, int r){
		for(int i=0; i<r; ++i ){
			if(v[i]==v[r]||abs(v[i]-v[r])==(r-i))
				return false;
		}
		return true;
	}
	void dfs(vector<int>& visit, int step, int deep, int& count){
		if(step==(deep-1))
			count++;
		for(int i=0; i<deep; ++i){
			visit.push_back(i);
			if(isValid(visit,step+1))
				dfs(visit,step+1,deep,count);
			visit.pop_back();
		}
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Solution test;
	cout<<test.totalNQueens(1)<<endl;
	return 0;
}

