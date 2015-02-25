// integerToRoman.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <iostream>
using namespace std;
class Solution {
public:
	string intToRoman(int num) {
		string letter[] ={"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
		int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
		string res;
		for (int i=0;i<13;i++)
		{
			while (num>=values[i])
			{
				num-=values[i];
				res+=letter[i];
			}
		}
		return res;

	}
};	
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

