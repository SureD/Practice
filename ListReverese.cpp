// BOP1.2.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
struct Node {
	Node *next;
	int x;
};
Node* RevereseLa(Node * head) //�ǵݹ�
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
void RevereseLr(Node *p,Node *head) //˫�����ݹ�
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
Node *RevereseLr1(Node *node) //�������ݹ�
{
	if(node==NULL||node->next==NULL)
		return node;
	Node *nextnode=node->next;
	node->next=NULL;
	Node *reversenode = RevereseLr1(nextnode);
	nextnode->next=node;
	return reversenode;
}
Node* Revereseh(Node *head) //ͷ�巨  ����������ָ��
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
	//head=RevereseLa(head);// a�ǵݹ��㷨���ص�Ϊhead->next
	//tmp=head->next;
	//////////////////////
	//RevereseLr(head->next,head);// ˫�����ĵݹ��㷨
	//tmp=head->next;
	////////////////
	//tmp=RevereseLr1(head); //�������ĵݹ��㷨
	//////////////
	tmp=Revereseh(head);  //ͷ�巨��ת ��������ָ��
	tmp=tmp->next;
	while(1)
	{
		
		if(tmp->next==NULL)
			break;
		std::cout<<tmp->x<<std::endl;
		tmp=tmp->next;
	}
}

