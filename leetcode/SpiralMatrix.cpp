// SpiralMatrix.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
	typedef pair<int,int> Positon;
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		Positon left(0,0);
		vector<int> ans;
		if(matrix.empty())
			return ans;
		Positon right(matrix.size()-1,matrix[0].size()-1);
		int m = matrix.size(), n = matrix[0].size();
		while(ans.size()!=(m*n)){
			printMatrixSide(matrix,left,right,ans);
			left.first++;left.second++;
			right.first--;right.second--;
		}
		
		return ans;
	}
	void printMatrixSide(vector<vector<int>>& matrix, Positon& left, Positon& right, vector<int>& output){
		if(left==right){
			output.push_back(matrix[left.first][left.second]);
			return;
		}
		int rows, cols;
		int start, end;
		// print first row
		rows = left.first;
		start = left.second; end = right.second;
		for(int i=start;i<=end;++i)
			output.push_back(matrix[rows][i]);
		// print last column
		cols = right.second;
		start = left.first+1; end = right.first-1;
		for(int i=start;i<=end;++i)
			output.push_back(matrix[i][cols]);
		// print last row
		if(left.first!=right.first){
		rows = right.first;
		start = right.second; end = left.second;
		for(int i=start;i>=end;--i)
			output.push_back(matrix[rows][i]);
		}
		// print first column
		if(left.second!=right.second){
		cols = left.second;
		start = right.first-1; end = left.first+1;
		for(int i=start; i>=end;--i)
			output.push_back(matrix[i][cols]);
		}
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Solution test;
	vector<vector<int>> mat;
	vector<int> l;
	l.push_back(1);l.push_back(2);//l.push_back(3);
	mat.push_back(l);
	//l.clear();
	//l.push_back(4);l.push_back(5);l.push_back(6);
	//mat.push_back(l);
	//l.clear();
	//l.push_back(7);l.push_back(8);l.push_back(9);
	//mat.push_back(l);
	//l.clear();
	l = test.spiralOrder(mat);
	for_each(l.begin(),l.end(),[&](int i){cout<<i<<endl;});
	return 0;
}

