// ImplementstrStr.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
class Solution {
public:
	int A[100000];
	void getNext(char* str)
	{
		A[0] = -1;
		int i=0,k=-1;
		while (str[i])
		{
			if (k==-1||str[i]==str[k])
			{
				k++;
				i++;
				A[i]=k;
			}else{
				k = A[k];
			}
		}
	}
	int kmp(char *s1,char *s2){
		getNext(s2);
		int i=0,j=0;
		while(s1[i]!='\0'&&(j==-1||s2[j]!='\0'))
		{
			if (j==-1||s1[i]==s2[j])
			{
				i++;
				j++;
			}else{
				j = A[j];
			}

		}
		if (!s2[j]&&j!=-1)
		{
			return i-j;
		}else
			return -1;
	}

	int strStr(char *haystack, char *needle) {


		if (haystack == NULL || needle == NULL) 
			return -1;
		if (needle[0] == '\0') 
			return 0;
		return kmp(haystack,needle);

	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Solution test;
	cout<<test.strStr("mississippi", "issi")<<endl;
	return 0;
}

