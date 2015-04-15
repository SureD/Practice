// WildcardMatching.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
class Solution {
public:
	// TLE
	bool isMatchRecursive(const char *s, const char *p) {
		if(*p=='\0') return *s=='\0';
		//if(*s=='\0') return *p=='\0';
		if(*p!='?'&&*p!='*'&&*p!=*s) return false;
		while(*s!='\0'&&*p!='\0'&&*s==*p||(*s!='\0'&&*p=='?')&&*p!='*'){
			s++;
			p++;
		}
		if(*p!='?'&&*p!='*'&&*p!=*s) return false;
		while(*(p+1)=='*') p++;
		while(*s!='\0'&&*p!='\0'&&*s!='\0'&&*p=='*'){
			if(isMatchRecursive(s,p+1))
				return true;
			s++;
		}
		
		return isMatchRecursive(s,p+1);
	}
	// wrong recursive
	bool recursive(const char *s, const char *p){
		if(*p=='\0') return *s=='\0';
		while(*p==*s||*p=='?'){
			s++;
			p++;
		}
		while(*s!='\0'&&*p=='*'){
			if(recursive(s,p+1))
				return true;
			s++;
		}
		while(*p=='*') p++;
		return *p=='\0';

	}
	// accept
	bool isMatch(const char *s, const char *p) {
		if(*p=='\0') return *s=='\0';
		//if(*s=='\0') return *p=='\0';
		const char* starS=NULL,*starP=NULL;
		while(*s!='\0'){
				if(*s==*p||*p=='?'){
					s++;
					p++;
					continue;
				}
				if(*p=='*'){
					p++; // skip *
					starP=p;
					starS=s;  //match at position 0
					continue;
				}
				if(starP!=NULL){
					p = starP;  // trace back
					starS++;
					s = starS;  // match from the next postion
					continue;
				}
				return false;
		}
		while(*p=='*') p++;   // skip the *
		if(*s=='\0'){
			return *p=='\0';
		}else
			return false;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Solution test;
	cout<<test.recursive("aab", "c*a*b")<<endl;
	return 0;
}

