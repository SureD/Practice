// RemoveElement.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;
class Solution {
public:
	int removeElement(int A[], int n, int elem) {
		int index = 0;
		for (int i=0;i<n;i++)
		{
			if (A[i]!=elem)
			{
				A[index++]=A[i];
			}
		}
		return index;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

