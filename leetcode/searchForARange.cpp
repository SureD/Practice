// searchForARange.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	vector<int> searchRange(int A[], int n, int target) {
		vector<int> ans;
		ans.push_back(-1);//left
		ans.push_back(-1);//right
		int mid = binarySearch(A,0,n-1,target);
		if(mid==-1)
			return ans;
		else{
			int left = binarySearch(A,0,mid-1,target);
			int right = binarySearch(A,mid+1,n-1,target);
			int tmp = left;
			while (tmp!=-1){
				left =tmp;
				tmp = binarySearch(A,0,left-1,target);
			}
			tmp = right;
			while (tmp!=-1){
				right = tmp;
				tmp = binarySearch(A,right+1,n-1,target);
			}
			if (left!=-1){
				ans[0] = left;
			}else
				ans[0] = mid;
			if (right!=-1){
				ans[1] = right;
			}else
				ans[1] = mid;

		}
		return ans;

	}
	int binarySearch(int A[],int left,int right,int target)
	{
		if (left>right)
			return -1;
		int mid;
		while (left<=right){
			 mid = left + (right-left)/2;
			 if (A[mid]==target)
				 return mid;
			 if (A[mid]>target)
				 right = mid-1;
			 if (A[mid]<target)
				 left = mid+1;
		}
		return -1;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	int A[] = {2,2};
	Solution test;
	vector<int> ans;
	ans = test.searchRange(A,2,2);
	cout<<ans[0]<<ans[1]<<endl;
	return 0;
}

