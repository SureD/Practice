// LCS.cpp : �������̨Ӧ�ó������ڵ㡣
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
	d[1] = A[0]; //d�������±��ʾ���ȣ����е����ݱ�ʾ�γ��������һ������������һ�������ڴ���������С�����һ��������ô��Ȼ���Ȼ��1������������
				//��һ����������С�����Ÿ���Ŀ��ܻ���ָ���������У�����滻����һ�������ö��ֲ��ҵ�middle
	for(int i=1;i<n;i++)
	{
		int left = 1; int right = len; int middle;
		while(left<=right)
		{
			middle = left+((right-left)>>1);
			if(A[i]>d[middle]) left=middle+1;
			else right =middle-1;
		}
	d[left]=A[i];//ѡ��left��Ϊ�±꣬��Ϊ��whileֹͣʱleft��λ��right����һ���������±ȵ�ǰֵ�����һ����
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

