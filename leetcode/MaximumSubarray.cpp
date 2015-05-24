// MaximumSubarray.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int addNow = 0;
		int addMax = INT_MIN;
		for(int i=0;i<nums.size();i++){
			addNow+=nums[i];
			addMax = max(addMax,addNow);
			if(addNow<0){
				addNow = 0;
			}
		}
		return addMax;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

