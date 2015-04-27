// Searcha2DMatrix.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	bool searchMatrix(vector<vector<int> > &matrix, int target) {
		if(matrix.size()==0)
			return false;
		int i=0,j=0;
		while(i<matrix.size()&&j<matrix[0].size()){
			if(target==matrix[i][j])
				return true;
			else if(i<(matrix.size()-1)&&target>=matrix[i+1][j])
				i++;
			else 
				j++;
		}
		return false;
	}

	bool searchMatrix2(vector<vector<int> > &matrix, int target){
		int m = matrix.size(),n = matrix[0].size();
		for(int r = 0, c = n-1;r<m&&(c>=0);){
			if(matrix[r][c]>target){
				c--;
			}else if(matrix[r][c]<target){
				r++;
			}else
				return true;
		}
		return false;
	}
	// divide and conquer
	bool find(vector<vector<int>>& a, int x1, int y1, int x2, int y2, int target ){
		if(x1>x2||y1>y2)
			return false;
		int midx = (x1+x2)>>1;
		int midy = (y1+y2)>>1;
		if(a[midx][midy]==target)
			return true;
		return (a[midx][midy]>target)?
			 (find(a,x1,y1,midx-1,y2,target)||find(a,midx,y1,x2,midy-1,target)):
			 (find(a,x1,midy+1,x2,y2,target)||find(a,midx+1,y1,x2,midy,target));
	}

	bool searchMatrix3(vector<vector<int> > &matrix, int target){
		int m = matrix.size(),n = matrix[0].size();
		return find(matrix,0,0,m-1,n-1,target);
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

