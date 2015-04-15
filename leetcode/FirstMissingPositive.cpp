// FirstMissingPositive.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
class Solution {
public:
	int firstMissingPositive(int A[], int n) {
		// Note: The Solution object is instantiated only once and is reused by each test case.
		if(NULL==A || n<1)                                                                                                                                   
			return 1;
		int pos=0;
		while(pos<n)
		{   
			if(A[pos]>0 && A[pos] != pos+1 && A[pos]-1<n && A[pos]!=A[A[pos]-1])
			{                                                                                                                                                
				swapP(&A[pos],&A[A[pos]-1]);   
			}   
			else
				++pos;
		}   
		for(int i=0;i<n;++i)
		{   
			if(i+1 != A[i])
				return i+1;                                                                                                                                  
		}   
		return n+1;
	}

	// trival method
	int firstMissingPositive2(int A[], int n) {
		if(n==1){
			if(A[0]!=1)
				return 1;
			else
				return 2;
		}
		int count=1;

		for(int i=0;i<n;i++,count++){
			if(A[i]>0&&count!=A[i]&&A[i]<=n){
				swapP(A+A[i]-1,&A[i]);
				if(A[i]>0&&count!=A[i]&&A[i]<=n)
					swapP(&A[i],A+A[i]-1);
			}
		}
		for(int i=0;i<n;i++,count++){
			if(A[i]>0&&count!=A[i]&&A[i]<=n){
				swapP(A+A[i]-1,&A[i]);
				if(A[i]>0&&count!=A[i]&&A[i]<=n)
					swapP(&A[i],A+A[i]-1);
			}
		}
		for(int i=0;i<n;i++,count++){
			if(A[i]>0&&count!=A[i]&&A[i]<=n){
				swapP(A+A[i]-1,&A[i]);
				if(A[i]>0&&count!=A[i]&&A[i]<=n)
					swapP(&A[i],A+A[i]-1);
			}
		}
		int i=0;
		count=1;
		while(A[i]<=0&&A[i]>n) i++;
		for( ;i<n;i++,count++){
			if(A[i]!=count)
				break;
		}
		return count;
	}
	void swapP(int*a,int *b){
		int tmp = *b;
		*b = *a;
		*a = tmp;
	}

	// this solution can only pass half case which do not contain repeat numbers using expectsum-realsum 
	int firstMissingPositive1(int A[], int n) {
		if(n==0)
			return 1;
		int realN = n;
		int mina=INT_MAX,maxa=INT_MIN;
		int ans;
		long long realsum=0;
		int countMax=n;
		long long expectSum=0;
		for(int i=0;i<n;i++){
			if(A[i]<=0)
				countMax--;
		}
		realN = countMax;
		for(int i=0;i<n;i++){
			if(A[i]>countMax){
				realN--;
				continue;
			}
			if(A[i]<=0)
				continue;
			realsum+=A[i];
			mina = A[i]<mina?A[i]:mina;
			maxa = A[i]>maxa?A[i]:maxa;
		}
		if(realN==0)
			return 1;
		if(mina!=1)
			return 1;
		expectSum = (1+maxa)*maxa/2;
		if(realsum==expectSum)
			return maxa+1;
		else if(expectSum>realsum)
			return (expectSum-realsum);
		else 
			return maxa+1;
			
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	int A[]={3,-1,23,7,21,12,8,9,18,21,-1,16,1,13,-3,22,23,13,7,14,3,6,4,-3};
	Solution test;
	cout<<test.firstMissingPositive(A,24)<<endl;
	return 0;
}

