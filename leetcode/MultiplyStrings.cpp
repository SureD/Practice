// MultiplyStrings.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

// count on the negative numbers
class Solution {
public:
	string multiply(string num1, string num2) {

		if(num1.empty()||num2.empty())
			return "";
		int sign1 = revereseString(num1);
		int sigh2 = revereseString(num2);
		sign1*=sigh2;
		int i,j;
		int *ans = new int[num1.length()+num2.length()+1];
		for(i=0;i<num1.length()+num2.length();i++)
			ans[i]=0;
		
		int count=0;
		for(i=0;i<num1.size();i++){
			for (j=0;j<num2.size();j++){
				ans[i+j]+=(num1[i]-'0')*(num2[j]-'0');
			}
		}
		count = i-1+j;
		i=0;
		int up=0;
		while(i<count){
			ans[i]+=up;
			int tmp=ans[i];
			up = 0;
			if(tmp>9){
				up +=  tmp/10;
				ans[i] = tmp%10;
			}
			i++;
		}
		while(up>0){
			ans[count] = up%10;
			up/=10;
			count++;
		}
		string ret;
		i=0;
		while(ans[count-1]==0&&count>0) count--;
		if(count==0)
			return "0";
		while(i<count)
			ret+=ans[i++]+'0';
		revereseString(ret);
		if(sign1==-1){
			return "-"+ret;
		}
	

		return ret;

	}
	int revereseString(string &str){
		int i=0;
		int sign=1;
		while(str[i]==' ')i++;
		if(str[i]=='+')  i++;
		if(str[i]=='-') {
			i++;
			sign = -1;
			str = str.substr(i,str.length()-i);
		}
		i=0;
		int j = str.length()-1;
		while(i<j){
			char tmp = str[i];
			str[i] = str[j];
			str[j] = tmp;
			i++;
			j--;
		}
		return sign;

	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	string a = "9133";
	string b = "0";
	Solution test;
	cout<<test.multiply(a,b)<<endl;
	cout<<a<<endl;
	return 0;
}

