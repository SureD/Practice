// PermutationsII.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <vector>
// ȫ�������⣺
// ����dfs�������б������ӵ�i����i֮���j��Ԫ�����ν�����Ȼ���j+1�ݹ���ã����Եõ�ȫ��������
// ȥ�صķ���������[i,j)֮������num[j]��ͬ�����֣���������ķ������ٴν���������ظ������ֻ����һ�μ��ɵõ����ظ���ȫ����
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

