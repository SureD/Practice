// PermutationsII.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
// 全排列问题：
// 利用dfs方法进行遍历，从第i个与i之后第j的元素依次交换，然后从j+1递归调用，可以得到全部的排列
// 去重的方法：若在[i,j)之间有与num[j]相同的数字，根据上面的方法若再次交换会出现重复，因此只交换一次即可得到不重复的全排列
using namespace std;
class Solution {
	public:
		vector<vector<int> > permuteUnique(vector<int> &num) {
			vector<vector<int> > ans;
			dfs(0,num.size(),num,ans);
			return ans;
		}
		bool canSwap(vector<int>& num, int i,int j) //[i,j)
		{
			for(int k = i;k<j;++k){
				if(num[k]==num[j])
					return false;
			}
			return true;
		}

		void dfs(int deep,int step,vector<int>& num, vector<vector<int>>& ans){
			if(deep==step)
				ans.push_back(num);
			for(int i=deep;i<step;++i){
					if(canSwap(num,deep,i)){
						swap(num[deep],num[i]);
						dfs(deep+1,step,num,ans);
						swap(num[deep],num[i]);
					}
			}
		}
};
int _tmain(int argc, _TCHAR* argv[])
{
	Solution test;
	vector<int> a;
	a.push_back(1);
	test.permuteUnique(a);
	return 0;
	return 0;
}

