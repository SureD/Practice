// BiTree.h : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
template<class T>
struct BiTree
	{
	T data;
	BiTree<T> * lchild;
	BiTree<T> * rchild;
	BiTree<T> * parent;
	BiTree(T nodevalue=T(),BiTree<T> *leftnode=NULL,BiTree<T>*rightnode=NULL,BiTree<T>*parentnode=NULL):data(nodevalue),lchild(leftnode)
		,rchild(rightnode){};
	};
template<class T>
class BinTree
{
	BiTree<T>* root;
public:
	BinTree(BiTree<T>* proot=NULL):root(proot){};
	~BinTree(){destory(root);};
	void Insertnode(const T& _value);
	//void deletenode(const T& _value);
	void const visit (BiTree<T>* _node){std::cout<<_node->data<<endl;};
	void printpreorder(){if(root)preorder(root);}; 
private:
	void Inserter(const T& _value);
	void destory(BiTree<T> *_node);
	void preorder(BiTree<T> * _node);

};

template<class T>
void BinTree<T>::Insertnode(const T& _value)
{
	if(root)
	{
		Inserter(_value);
	}else
		{
			root = new BiTree<T>;
			root->data = _value;
			root->lchild = nullptr;
			root->rchild = nullptr;
			root->parent = nullptr;
		}
}

template<class T>
void BinTree<T>::Inserter(const T& _value)
{
	BiTree<T> *_t_ptr=NULL;
	BiTree<T> *_t_ptrr=NULL;
	BiTree<T> *_t_ptrl=NULL;
	_t_ptr = root;
	while(_t_ptr!=NULL)
	{
		_t_ptrr=NULL;
		_t_ptrl=NULL;
		if(_value>=_t_ptr->data){
			_t_ptrr=_t_ptr;
			_t_ptr=_t_ptr->rchild;
		}
		else
		{
			_t_ptrl=_t_ptr;
			_t_ptr = _t_ptr->lchild;
		}
	}
	if(_t_ptrr)
	{
		_t_ptrr->rchild = new BiTree<T>;
		_t_ptrr->rchild->rchild = nullptr;
		_t_ptrr->rchild->lchild = nullptr;
		_t_ptrr->rchild->parent = _t_ptr;
	}else
	{
		_t_ptrl->rchild = new BiTree<T>;
		_t_ptrl->rchild->rchild = nullptr;
		_t_ptrl->rchild->lchild = nullptr;
		_t_ptrl->rchild->parent = _t_ptr;

	}
	
}
template<class T>
void BinTree<T>::destory(BiTree<T>* _node)
{
	if(_node)
	{
		destory(_node->rchild);
		destory(_node->lchild);
		delete _node;
	}
}
template<class T>
void BinTree<T>::preorder(BiTree<T> *_node)
{
	if(_node)
	{
		visit(_node);
		preorder(_node->lchild);
		preorder(_node->rchild);
	}
}
