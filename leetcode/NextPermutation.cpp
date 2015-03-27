// NextPermutation.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	void reverseVec(vector<int> &num,int left=0)
	{
		int right = num.size()-1;
		int tmp;
		while (left<right)
		{
			tmp = num[left];
			num[left] = num[right];
			num[right] = tmp;
			left++;
			right--;
		}
	}
	void nextPermutation(vector<int> &num) {
		int length = num.size();
		int loops = length-1;
		int curValue = num[length-1];
		while(loops){
			if (num[loops]<=num[loops-1])
			{
				loops--;
			}else
				break;
		}
		if (loops==0)
		{
			reverseVec(num);
			return;
		}
		loops--;
		curValue=num[loops];
		int idx = loops+1;
		while (idx<length&&num[idx]>curValue) idx++;
		idx--;

		num[loops] = num[idx];
		num[idx] = curValue;
		reverseVec(num,loops+1);

		return;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	Solution test;
	vector<int> a;
	a.push_back(2);
	a.push_back(3);
	a.push_back(1);
	//a.push_back(2);
	//a.push_back(2);
	vector<int>::iterator iter;
	test.nextPermutation(a);
	for (iter = a.begin();iter!=a.end();iter++)
	{
		cout<<*iter<<endl;
	}
	return 0;
}

