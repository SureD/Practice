// RotateImage.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
using namespace std;
class Solution {
public:
	void rotate(vector<vector<int> > &matrix) {
		up2down(matrix);
		reverese(matrix);
	}
	void reverese(vector<vector<int>>& matrix){
		int n = matrix.size();
		for(int i=0;i<n;++i){
			for(int j=i;j<n;++j)
				swap(matrix[i][j],matrix[j][i]);
		}
	}
	void up2down(vector<vector<int>> &matrix) {
		int n = matrix.size();
		int i = 0,j = n-1;
		while(i<j){
			swap(matrix[i],matrix[j]);
			i++;
			j--;
		}
	}

};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

