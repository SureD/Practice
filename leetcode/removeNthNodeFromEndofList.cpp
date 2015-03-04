// removeNthNodeFromEndofList.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
		ListNode* p=head;
		ListNode* q=p;
		ListNode* pre =NULL;
		for (int i=0;i<n-1;i++)
			q=q->next;
		while (q->next)
		{
			pre=p;
			p=p->next;
			q=q->next;
		}
		if (pre==NULL)
		{
			head = p->next;
			return head;
		}else
		{
			pre->next=p->next;
			return head;
		}
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

