// SwapNodesinPairs.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
/*
 Definition for singly-linked list.
*/ 
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        ListNode* ret=new ListNode(-1);
		ListNode *p,*q,*r;
		ListNode* last = ret;
		p = head;
		ret->next = p;
		while (p!=NULL&&p->next!=NULL)
		{
			
			q = p->next;
			r = q->next;
			p->next = r;
			q->next = p;
			last->next = q;
			last = last->next->next;
			p = r;
		}
		return ret->next;
		
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

