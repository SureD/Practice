// JumpGame.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
	bool canJump(vector<int>& nums) {
		if(nums.size()==1)
			return true;
		int curMax = 0;
		for(int i=0;i<nums.size();++i){
			curMax = max(curMax,nums[i]+i);
			if(curMax>=(nums.size()-1))
				return true;
			if(nums[i]==0){
				if(curMax<=i)
					return false;
			}
		}
		return true;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

