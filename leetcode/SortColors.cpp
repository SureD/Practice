// SortColors.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
class Solution {
public:
	/************************************************************************/
	/* i = 0,j = n;
	/* a[0,i-1] = 0;
	/* a[i,k-1] = 1;
	/* a[k,j-1] = unknown;
	/* a[j,n-1] = 2;
	/* k = 0->j-1;
	/* a[k] = 0; swap(a[i++],a[k]);
	/* a[k] = 1; continue
	/* a[k] = 2; swap(a[--j],a[k--]);
	/************************************************************************/
	void sortColors(int A[], int n) {
		int i = 0, j = n;
		for(int k = 0; k<j;k++){
			if(A[k]==1)
				continue;
			else if(A[k]==0)
				swap(&A[i++],&A[k]);
			else
				swap(&A[--j],&A[k++]);
		}
	}
	void swap(int* a, int* b){
		int t = *a;
		*a = *b;
		*b = t;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

