// MergekSortedLists.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/**
 * Definition for singly-linked list.
 */
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
#define INF 1000000
struct cmp{
	bool operator()(ListNode* l1,ListNode* l2){
		return l1->val>l2->val;
	}
};
typedef priority_queue<ListNode*,vector<ListNode*>,cmp> Heap;

 
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
		if (lists.empty())
		{
			return NULL;
		}
		ListNode *head = new ListNode(0);
		ListNode *p = head;
		Heap hp;
		for (int i=0;i<lists.size();i++)
		{
			if (lists[i]!=NULL)
			hp.push(lists[i]);
		}
		if (hp.size()==0)
		{
			return NULL;
		}
		int minValue = hp.top()->val;
		while (!hp.empty())
		{
			ListNode *temp;
			temp = hp.top();
			p->next = temp;
			hp.pop();
			p = p->next;
			if (temp->next)
			{
				hp.push(temp->next);
			}
		}
		return head->next;  
    }
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

