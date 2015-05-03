// Pow(xn).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
class Solution {
public:
	double myPow(double x, int n) {
		double res = 1.0;
		int flag = 1;
		if(n==0) return 1;
		if(abs(x)==1.0){ 
			if(n%2)
				return x;
			else
				return 1;
		}
		if(n<0){
			flag = -1;
			n = -n;
		}
		for(;n;n>>=1){
			if(n&1)
				res = x*res;
			x = x*x;
		}
		return flag>0?res:1/res;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

