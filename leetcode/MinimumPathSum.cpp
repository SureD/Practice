// MinimumPathSum.cpp : 定义控制台应用程序的入口点。
//
// using DP
#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	// can optimize the space by using d[j] = min(d[j],d[j-1])+grid[i][j]
	int minPathSum(vector<vector<int> > &grid) {
		int m = grid.size();
		int n = grid[0].size();
		vector<vector<int>> dp(m,vector<int>(n));
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++){
				if(i==0){
					if(j==0)
						dp[i][j] = grid[i][j];
					else
						dp[i][j] = dp[i][j-1]+grid[i][j];
				}else if(j==0)
					dp[i][j] = dp[i-1][j]+grid[i][j];
				else
					dp[i][j] = min(dp[i][j-1],dp[i-1][j])+grid[i][j];
			}
		return dp[m-1][n-1];
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

