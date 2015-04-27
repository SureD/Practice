// JumpGameII.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Solution {
public:
	// really nice and simple solution !
	// refer to http://www.cnblogs.com/ganganloveu/p/3761715.html
	// and some other useful solutions :http://blog.csdn.net/lanxu_yy/article/details/11714231
	int jumpgreedy(int A[], int n){
		int curReach=0;
		int curMax=0;
		int i=0;
		int jumps=0;
		for(i=0;i<n;i++){
			if(curReach<i){
				jumps++;
				curReach = curMax;
				
			}
			curMax = max(curMax,A[i]+i);
		}
		return jumps;

	}

	// BFS.........can not pass the last big case!  FUCK!!
	int jump(int A[], int n) {
		queue<int> q;
		if(A==NULL||n==0)
			return 0;
		int flag = 0;
		if(A[0]==1){
			int i=1;
			while(i<n&&A[i]==A[i-1]) i++;
			if(i==n) return n-1;
		}
		vector<int> maxjump(n);
		int deep = 0;
		int *visit = new int[n];
		memset(visit,0,sizeof(int)*n);
		q.push(n-1);
		while(!q.empty()){
			int now;
			int count = q.size();
			for(int j=0;j<count;j++){
				now = q.front();
				if(now==0)
					return deep;
				q.pop();
				for(int i=0;i<now;i++){
					if(!visit[i]&&maxjump[i]>=now){
						visit[i] = 1;
						q.push(i);
					}
				}
			}
			deep++;
		}
		return deep;
	}

	// DFS ------>simple but TLE :(
	int jumpdfs(int A[], int n) {
		if(A==NULL||n==0)
			return 0;
		vector<int> maxjump(n);
		for(int i=0;i<n;i++){
			int tmp = A[i]+i;
			tmp = tmp<n?tmp:n-1;
			maxjump[i] = tmp;
		}
		int ans = n+1;
		dfs(maxjump,n-1,ans,0);
		return ans;
	}
	void dfs(vector<int>& maxjump,int pos, int& minj,int deep){
	
		if(pos==0){
			minj = deep<minj?deep:minj;
			return;
		}
		if(deep>minj)
			return;
		for(int i=0;i<pos;i++){
			if(maxjump[i]>=pos)
				dfs(maxjump,i,minj,deep+1);
		}
		return ;
	}

};

int _tmain(int argc, _TCHAR* argv[])
{
	int A[] = {2,3,1,1,4};
	Solution test;
	cout<<test.jump(A,5)<<endl;
	return 0;
}

