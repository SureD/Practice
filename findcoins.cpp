// findcoins.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;
// �������̶ֹ�����Ǯ�ң����������ٵ�Ǯ�Ҹ��������ĳ���ķ���
int findcoins(int A[],int _len, int _money)
{
	int *d = new int[_money+1];
	d[0]=0;
	for(int i=1;i<=_money;i++)
	{
		d[i]=_money+1;
		for(int j=0;j<_len;j++)
		{
			if(A[j]<=i&&(d[i-A[j]]+1)<d[i]) d[i]=d[i-A[j]]+1;
			
		}
	}
	int ans =d[_money];
	delete[] d;
	return ans;
}
int main(int argc, _TCHAR* argv[])
{
	int coin[]={1,3,5};
	int money=11;
	int len=3;
	cout<<findcoins(coin,len,money)<<endl;
	return 0;
}

