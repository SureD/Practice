#include "stdafx.h"
#include "BiTree.h"
#include<iostream>
#include<string>
using namespace std;
string& findab(const string& a, string &b)
{
	if(a.empty()||b.empty())
		return b;
	int flag[2];
	int count =0;
	string temp1;
	bool flag0=1;
	int lengths=0;
	for(int i=0;i<a.length();++i)
	{
	
		if(count==2)
		{
			count=0;
			string c=a.substr(flag[0]+1,flag[1]-1-flag[0]);
			string d=b.substr(flag[0]+1,flag[1]-1-flag[0]);
			if(flag0&&c==d)
			{
				lengths+=(flag[1]-flag[0]);
				i--;
				
			}
			else
			{	
				i--;
				flag0=0;
				temp1.append("../");
			}
			
				
		}
		if(a[i]=='/')
		{
			flag[count]=i;
			count++;

		}
	}
	b.erase(0,lengths+1);
	b.insert(0,temp1);
	return b;
}
int main()
{
	//BinTree<int> a;
	//a.Insertnode(1);
	//return 1;
	string a= "/qihoo/app/b/c/d/new.c";
	string b= "/qihoo/app/1/2/test.c";
	b=findab(a,b);
	cout<<b<<endl;
}

using namespace std;    
struct Coord{
	int x,y;
};  
template<int row,int col>
Coord findkey(float(&mat)[row][col],const float &key)
{
	Coord ans;
	ans.x=row;ans.y=col;
	if(key<mat[row-1][col-1]||key>mat[0][0])
	{
		cout<<"No answer"<<endl;
		return Coord;
	}
	int i=0,j=col-1;
	while(i<=row&&j>=0)
	{
		if(key==mat[i][j]) break;
		else if(key>mat[i][j])
			--j;
		else
			++i;
	}
	ans.x=i;
	ans.y=j;
	return ans;
}
