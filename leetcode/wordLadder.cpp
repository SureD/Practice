// wordLadder.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <set>
#include <unordered_set>
#include <queue>
#include <map>
using namespace std;
class Solution {
public:
	int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
		if(beginWord==endWord)
			return 0;
		if(wordDict.empty())
			return 0;
		queue<string> qStr;
		map<string,int> len;
		len[beginWord] = 1;
		qStr.push(beginWord);
		for(;!qStr.empty();qStr.pop()){
			string tmpWord = qStr.front();
			int step = len[tmpWord] + 1;
			for(int i=0;i<tmpWord.length();i++){
				for(int c='a';c<='z';c++){
					int tempChar = tmpWord[i];
					tmpWord[i] = c;
					if(wordDict.find(tmpWord)!=wordDict.end()&&len.find(tmpWord)==len.end()){
						if(tmpWord==endWord)
							return step;
						qStr.push(tmpWord);
						len.insert(make_pair(tmpWord,step));
					}
					tmpWord[i] = tempChar;
				}
			}

		}
		return 0;

	}

	
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

