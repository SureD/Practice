// containerWithMostWater.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int maxArea(vector<int> &height) {
		int left=0,right = height.size()-1;
		int ans = 0;
		while(left<right)
		{
			ans = max(ans,min(height[left],height[right])*(right-left));
			if(height[left]<height[right])
				left++;
			else
				right--;
		}
		return ans;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

