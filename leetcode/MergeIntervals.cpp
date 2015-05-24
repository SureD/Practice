// MergeIntervals.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//  Definition for an interval.
  struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
  };
 
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
		vector<Interval> ret;
		if(intervals.empty())
			return ret;
		sort(intervals.begin(), intervals.end(),[&](const Interval&a,const Interval&b){ return a.start<b.start;});
		Interval s = intervals[0];
		Interval e;
		for(int i=1; i<intervals.size();++i){
			Interval e = intervals[i];
			if(s.end<e.start){
				ret.push_back(s);
				s = e;
			}else{
				s.start = min(s.start,e.start);
				s.end = max(s.end,e.end);
			}
		}
		if(s.start!=e.start||s.end!=e.end)
			ret.push_back(s);
		return ret;
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	Interval s(1,4),e(0,4);
	vector<Interval> ff;
	ff.push_back(s);ff.push_back(e);
	Solution test;
	test.merge(ff);
	return 0;
}

