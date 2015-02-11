// MedianOfTwoSortedArrays.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
class Solution{
public:
	int binaryInsert(int A[],int length,int target){
		int low=0,high=length-1;
		int mid;
		while(low<high){
			mid = low + (high-low)/2;
			if(A[mid]>=target)
				low =mid+1;
			else
				high = mid-1;
		}
		return low;
	}
	double findFirstArray(int A[],int m,int B[],int n){
		int low = 0; int high = m -1;int mid;int insert_pos;
		while(low<high){
			mid = low + (high-low)/2;
			insert_pos = binaryInsert(A,m,A[mid]);
			if ((mid+insert_pos)==(m+n)/2)
			{
				return A[mid];
			}

		}
		return -1;
	}
	double findMedianSortedArrays(int A[], int m, int B[], int n) {
		double ans = findFirstArray(A,m,B,n);
		if (ans==-1)
		{
			ans = findFirstArray(B,n,A,m);
		}
		return ans;
	}

};

int _tmain(int argc, _TCHAR* argv[])
{
	int A[] = {1,2,3,4};
	int B[] = {5,6,7,8,9};
	Solution test;
	cout<<test.findMedianSortedArrays(A,4,B,5)<<endl;
	return 0;
}

