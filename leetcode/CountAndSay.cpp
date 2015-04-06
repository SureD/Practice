// CountAndSay.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
	string countAndSay(int n) {
		string ans="1";
		string tmp;
		while(n--){
			tmp.clear();
			int repeatCount = 0;
			for(int i=0;i<ans.length();i++){
				while(i<(ans.length()-1)&&ans[i]==ans[i+1]){
					i++;
					repeatCount++;
				}
				if (repeatCount!=0){
					tmp+=repeatCount+'1';
					tmp+=ans[i];
					repeatCount=0;
					continue;
				}
				tmp+="1";
				tmp+=ans[i];
			}
			ans.clear();
			ans = tmp;
		}
		return ans;
	}
};


int _tmain(int argc, _TCHAR* argv[])
{
	Solution test;
	cout<<test.countAndSay(4)<<endl;
	return 0;
}

