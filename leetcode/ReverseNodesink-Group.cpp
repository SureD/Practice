// ReverseNodesink-Group.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
/**
  Definition for singly-linked list.
**/ 
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
	ListNode* reverseKlink(ListNode *p,int i,int k)
	{
		if (i==k)
		{
			 return p;
		}
		ListNode* temp = reverseKlink(p->next,i+1,k);
		temp->next = p;
		p->next = NULL;
		return p;
	}
    ListNode *reverseKGroup(ListNode *head, int k) {
		int j = 1;
		ListNode* bhead = new ListNode(-1);
		bhead->next = head;
		ListNode* p = head;
		ListNode* tnext = NULL;
		ListNode* temphead = NULL;
		ListNode* ttail = bhead;
		ListNode* temp = NULL;
		ListNode* tempnext = NULL;
		while (p!=NULL&&p->next!=NULL)
		{
			if (j==1)
			{
				temphead = p;
			}
			if (j==k)
			{
				j=1;
				temp = ttail;
				tempnext = p->next;
				ttail = reverseKlink(temphead,1,k);
				temp->next = p;
				p = tempnext;
				continue;
			}
			j++;
			p = p->next;
		}
		if (j!=1)
		{
			ttail->next = temphead;
		}
		return bhead->next;
        
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

