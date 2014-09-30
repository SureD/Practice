// LCS.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include  <iostream>
using namespace std;
int Findlen(int A[],int n)
{
	int *d = new int[n];
	int len = 1;
	for(int i=0;i<n;i++)
	{
		d[i]=1;
		for(int j=0;j<i;j++)
			if(A[j]<=A[i]&&d[i]<=d[j]+1) d[i]=d[j]+1;
		if(d[i]>len) len=d[i];

	}
	delete[] d;
	return len;
}
int Findlen2(int A[],int n)
{
	int *d = new int[n];
	int len = 1;
	d[1] = A[0]; //d数组中下标表示长度，其中的数据表示次长度下最后一个数，若出现一个数大于此数，并且小于其后一个数，那么显然长度会加1，并且其优于
				//下一个数（比其小）有着更大的可能会出现更长的最长序列，因此替换掉下一个数，用二分查找的middle
	for(int i=1;i<n;i++)
	{
		int left = 1; int right = len; int middle;
		while(left<=right)
		{
			middle = left+((right-left)>>1);
			if(A[i]>d[middle]) left=middle+1;
			else right =middle-1;
		}
	d[left]=A[i];//选择left作为下标，因为当while停止时left会位于right的下一个，即更新比当前值大的下一个数
	if (left>len) len++;
	}
	delete[] d;
	return len;
}
int main()
{
	int A[]={5, 3, 4, 8, 6, 7,2,10,11,9};
	cout<<Findlen2(A,10)<<endl;
	return 0;
}

