// RemoveDuplicatesfromSortedArray.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
class Solution {
public:
	int removeDuplicates(int A[], int n) {
		if (n<2)
		{
			return n;
		}
		int key = A[0];
		int ret = n;
		int i;
		for ( i=n-2;i>=0;i--)
		{
			A[i+1] = A[i+1]-A[i];
		}
		i=1;
		int flag = 0;
		int last = 1;
		while (i<n)
		{
			while (A[i]==0&&i<n)
			{
				ret--;
				i++;
			}
			A[last] = key+A[i];
			key = A[last];
			last++;
			i++;
		}
		return ret;
	}
	int remove(int A[],int n)
	{
		if (n<2)
			return n;
		int index = 1;
		for (int i=1;i<n;i++)
		{
			if (A[i]!=A[i-1])
			{
				A[index++]=A[i];
			}
		}
		return index;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	int A[5] = {1,1,2,2,3};
	Solution test;
	cout<<test.removeDuplicates(A,5)<<endl;
	cout<<A[0]<<A[1]<<A[2]<<A[3]<<A[4]<<endl;
	return 0;
}

