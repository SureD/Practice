// TrappingRainWater.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <map>
#include <vector>
#include <iterator>  
using namespace std;
class Solution {
public:
	/*求面积的方法，没能考虑到哦全部的情况 只能过一半的case*/
	//typedef vector<int> localMax;
	//int trap(int A[], int n) {
	//	if (A==NULL||n==1)
	//		return 0;

	//	// find local max
	//	localMax lm;
	//	int i=0;
	//	if(A[i]>A[1])
	//		lm.push_back(i);
	//	for(i=1;i<n-1;i++){
	//		if(A[i]>A[i-1]&&A[i]>A[i+1])
	//			lm.push_back(i);
	//	}
	//	if(A[i]>A[i-1])
	//		lm.push_back(i);
	//	if(lm.size()<2)
	//		return 0;
	///*	 copy (lm.begin(), lm.end(), ostream_iterator<int> (cout, "\n"));  */
	//	// exclude the local min in lm
	//	localMax lm2;
	//	lm2.push_back(lm[0]);
	//	for (i=1;i<lm.size()-1;i++)
	//	{
	//		if(A[lm[i]]<A[lm[i-1]]&&A[lm[i]]<A[lm[i+1]])
	//			continue;
	//		else
	//			lm2.push_back(lm[i]);
	//	}
	//	lm2.push_back(lm[i]);
	//	
	//	// calc water
	//	int max1,max2,maxMin;
	//	int ans=0;
	//	for(int i=0;i<lm2.size()-1;i++){
	//		int length = 0,area = 0;
	//		max1 = lm2[i];
	//		max2 = lm2[i+1];
	//		maxMin = A[max1]<A[max2]?A[max1]:A[max2];
	//		for(int j=lm2[i];j<=lm2[i+1];j++){
	//			int tmp;
	//			length++;
	//			tmp = A[j]<maxMin?A[j]:maxMin;
	//			area+=tmp;
	//		}
	//		ans+=(length*maxMin-area);
	//	}
	//	return ans;
	//}
	int trap(int A[], int n) {
		if(A==NULL||n==1)
			return 0;
		vector<int> leftMax(n);
		vector<int> rightMax(n);
		int blockMax=0;
		for(int i=0;i<n;i++){
			blockMax = A[i]>blockMax?A[i]:blockMax;
			leftMax[i] = blockMax;
		}
		blockMax = 0;
		for(int i=n-1;i>=0;i--){
			blockMax = A[i]>blockMax?A[i]:blockMax;
			rightMax[i] = blockMax;
		}
		int ans=0;
		for(int i=0;i<n;i++){
			int tmp = leftMax[i]<rightMax[i]?leftMax[i]:rightMax[i];
			ans+=(tmp-A[i]);
		}
		return ans;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	int A[]={0,1,0,2,1,0,1,3,2,1,2,1};
	Solution test;
	cout<<test.trap(A,12)<<endl;
	return 0;
}

