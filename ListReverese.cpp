// BOP1.2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
struct Node {
	Node *next;
	int x;
};
Node* RevereseLa(Node * head) //非递归
{
	if(head==NULL||head->next==NULL)
	{
		return head;
	}
	Node *prv=NULL;
	Node *cur=head;
	Node *tmp;
	while(cur->next)
	{
		tmp=prv;
		prv=cur;
		cur=cur->next;
		prv->next=tmp;
	}
	cur->next=prv;
	head->next=cur;
	return head;
}
void RevereseLr(Node *p,Node *head) //双参数递归
{
	if(p->next==NULL)
	{
		head->next=p;
		return;
	}
	RevereseLr(p->next,head);
	p->next->next=p;
	p->next=NULL;
}
Node *RevereseLr1(Node *node) //单参数递归
{
	if(node==NULL||node->next==NULL)
		return node;
	Node *nextnode=node->next;
	node->next=NULL;
	Node *reversenode = RevereseLr1(nextnode);
	nextnode->next=node;
	return reversenode;
}
Node* Revereseh(Node *head) //头插法  仅利用两个指针
{
	Node *nnode= new Node();
	nnode->next=NULL;
	Node *p = head->next;
	//Node *tmp;
	while(p!=NULL)
	{
		head->next=p->next;
		p->next=nnode->next;
		nnode->next=p;
		p=head->next;
	}
	head->next=nnode->next;
	delete nnode;
	return head;
}

int main()
{
	Node* head = new Node();
	Node* tmp = head;
	for (int i = 0; i < 10; i++)
	{
		tmp->next=new Node();
		tmp->next->x=i;
		tmp->next->next=NULL;
		tmp=tmp->next;
	}
	//head=RevereseLa(head);// a非递归算法返回的为head->next
	//tmp=head->next;
	//////////////////////
	//RevereseLr(head->next,head);// 双参数的递归算法
	//tmp=head->next;
	////////////////
	//tmp=RevereseLr1(head); //单参数的递归算法
	//////////////
	tmp=Revereseh(head);  //头插法反转 利用两个指针
	tmp=tmp->next;
	while(1)
	{
		
		if(tmp->next==NULL)
			break;
		std::cout<<tmp->x<<std::endl;
		tmp=tmp->next;
	}
}

