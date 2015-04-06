// SearchInsertPosition.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
	int searchInsert(int A[], int n, int target) {
		if(n<0) return -1;
		return binSearch(A,0,n-1,n,target);
	}
	int binSearch(int A[],int left ,int right,int n,int target)
	{
		if(left>right) return -1;
		if (A[left]==target){
			return left;
		}
		if(A[right]==target)
			return right;
		int mid;
		while(left<=right){
			mid = left + (right - left)/2;
			if(A[mid]==target)
				return mid;
			if(A[mid]>target)
				right = mid - 1;
			if(A[mid]<target)
				left = mid + 1;
		}
		// left>right
		if(left>n-1)
			return left;
		if (target<A[left]){
			return left;
		}else
			return left+1;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	Solution test;
	int A[] = {1,3,5,6};
	cout<<test.searchInsert(A,4,0)<<endl;
	return 0;
}

