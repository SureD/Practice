// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
class Solution{
public:
	typedef pair<int,int> value_index;
	int binarySearch(int low,int high,int target,vector<value_index> &vecV_l)
	{
		if(low>high)
			return -1;
		int mid = low + (high-low)/2;
		if(vecV_l[mid].first == target)
			return mid;
		else if (vecV_l[mid].first < target)
		{
			binarySearch(mid+1,high,target,vecV_l);
		}else if(vecV_l[mid].first > target)
		{
			binarySearch(low,mid-1,target,vecV_l);
		}
	}
	vector<int> twoSum(vector<int> &numbers, int target) {
		vector<int> ans;
		vector<value_index> numbersPair;
		numbersPair.reserve(numbers.size());
		value_index v_i;
		for (int i=0;i<numbers.size();i++)
		{
			v_i.first = numbers[i];
			v_i.second = i;
			numbersPair.push_back(v_i);
		}
		sort(numbersPair.begin(),numbersPair.end(),
			[&](const value_index&v1,const value_index&v2)->bool
		{return v1.first<v2.first;});
		int index1,index2 = -1;
		int low =0,high = numbersPair.size()-1;
		for (int i=0;i<numbersPair.size();i++)
		{
			index1 = i;
			index2 = binarySearch(i+1,high,target-numbersPair[i].first,numbersPair);
			if (index2!=-1)
			{
				int ans1=index1,ans2=index2;
				if(numbersPair[index1].second>numbersPair[index2].second)
					{
						ans2 = index1;
						ans1 = index2;
				}
				ans.push_back(numbersPair[ans1].second+1);
				ans.push_back(numbersPair[ans2].second+1);
				break;
			}
		}
		return ans;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	Solution test;
	vector<int> input,a;
	input.push_back(-1);
	input.push_back(-2);
	input.push_back(-3);
	input.push_back(-4);
	input.push_back(-5);
	a = test.twoSum(input,-8);
	cout<<a[0]<<a[1]<<endl;
	return 0;
}

