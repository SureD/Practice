#include<iostream>
#include<stack>
using namespace std;
enum COLOR{Red,Black};
struct rb_node{
    rb_node *lchild,*rchild,*parent;
    int key;
    COLOR color;
};
rb_node *NIL;
// set NIL: the function you must call once
bool set_NIL(){
    NIL = new rb_node;
    NIL->color = Black;
    NIL->key = 7777;
    NIL->lchild = NIL->rchild = NIL->parent = NULL;
    return true;
}

// creat a rb_node
rb_node* get_node(rb_node* parent,int key);

// search operation
rb_node* rb_search_node(rb_node* root,int key);

// visit a rb_tree
void rb_in_order(rb_node* root);

// insert
bool insert_node(rb_node* root,int key);

//delete
rb_node* delete_node(rb_node* root,int key);
bool rb_delete_fixup(rb_node* root,rb_node* node);

// rotate
bool left_rotate(rb_node* root,rb_node* node);
bool right_rotate(rb_node* root,rb_node* node);

// insert fix-up

bool rb_insert_fixup(rb_node *root,rb_node* node);

// tree-successor
rb_node* rb_tree_successor(rb_node* node);

//=======================impletement=============

rb_node* get_node(rb_node* parent,int key)
{
    rb_node* ptr2node = new rb_node;
    ptr2node->lchild = NIL;
    ptr2node->rchild = NIL;
    ptr2node->parent = parent;
    ptr2node->key = key;
    ptr2node->color = Red;
    return ptr2node;
}

void rb_in_order(rb_node* root)
{
    if(root==NIL){
        cout<<"Error:Empty Red-Black Tree"<<endl;
        return;
    }
    stack<rb_node*> s;
    rb_node* node = root;
    while(node!=NIL||!s.empty()){
        if(node!=NIL){
            s.push(node);
            node = node->lchild;
        }else{
            node = s.top();
            s.pop();
            if(node->color==Black)
                cout<<node->key<<"...Black"<<endl;
            else
                cout<<node->key<<"...Red"<<endl;
            node = node->rchild;
        }
    }
}
bool left_rotate(rb_node* root,rb_node* node)
{
    rb_node *tmp_y = node->rchild;
    node->rchild = tmp_y->lchild;
    tmp_y->parent = node->parent;
    if(node->parent==NIL){
        root = tmp_y;
    }else if(node==(node->parent)->lchild){
        (node->parent)->lchild = tmp_y;
    }else if(node==(node->parent)->rchild){
        (node->parent)->rchild = tmp_y;
    }
    tmp_y->lchild = node;
    node->parent = tmp_y;
    return true;
}
bool right_rotate(rb_node* root,rb_node* node)
{
    rb_node *tmp_y = node->lchild;
    node->lchild = tmp_y->rchild;
    tmp_y->parent = node->parent;
    if(node->parent==NIL){
        root = tmp_y;
    }else if(node==(node->parent)->lchild){
        tmp_y = node->parent->lchild;
    }else if(node==(node->parent)->rchild){
        tmp_y = node->parent->rchild;
    }
    tmp_y->rchild = node;
    node->parent = tmp_y;
    return true;
}
bool rb_insert_fixup(rb_node* root,rb_node* node)
{
    while(node->parent->color==Red){
        rb_node *tmp_y;
        if(node->parent==node->parent->parent->lchild){
            tmp_y = node->parent->parent->rchild;
            if(tmp_y->color==Red){
                node->parent->color = Black;
                tmp_y->color = Black;
                node->parent->parent->color = Red;
                node = node->parent->parent;
            }else{
                    if(node==node->parent->rchild){
                        node = node->parent;
                        left_rotate(root,node);
                    } 
                    node->parent->color = Black;
                    node->parent->parent->color = Red;
                    right_rotate(root,node->parent->parent);
            }
        }
        else{
            tmp_y = node->parent->parent->lchild;
            if(tmp_y->color==Red){
                node->parent->color = Black;
                tmp_y->color = Black;
                node->parent->parent->color = Red;
                node = node->parent->parent;
            }else{
                    if(node==node->parent->lchild){
                        node = node->parent;
                        right_rotate(root,node);
                    }
                    node->parent->color = Black;
                    node->parent->parent->color = Red;
                    left_rotate(root,node->parent->parent);
            }
        }
    }
    root->color = Black;
    return true;
}

rb_node* rb_tree_successor(rb_node* node)
{
    rb_node* tmp_y;
    if(node->rchild!=NIL){
        tmp_y = node->rchild;
        while(tmp_y->lchild!=NIL)
            tmp_y = tmp_y->lchild;
        return tmp_y;
    }
    tmp_y = node->parent;
    while(tmp_y!=NIL&&node==tmp_y->rchild){
            node = tmp_y;
            tmp_y = tmp_y->parent;
    }
    return tmp_y;
}

rb_node* rb_search_node(rb_node* root, int key)
{
    if(root==NIL)
        return NIL;
    rb_node *tmp_x;
    tmp_x = root;
    while(tmp_x!=NIL)
    {
        if(key>tmp_x->key)
            tmp_x = tmp_x->rchild;
        else if(key<tmp_x->key)
            tmp_x = tmp_x->lchild;
        else if(key==tmp_x->key)
            break;
    }
    return tmp_x;
}
bool insert_node(rb_node* root,int key)
{
    rb_node *tmp_y = NIL;
    rb_node *tmp_z;
    rb_node *tmp_x = root;
    while(tmp_x!=NIL){
        tmp_y = tmp_x;
        if(key>tmp_x->key){
            tmp_x = tmp_x->rchild;
        }else if(key<tmp_x->key){
            tmp_x = tmp_x->lchild;
        }else{
            cout<<"error: same key value,insertion failed"<<endl;
            return false;
        }
    }
    tmp_z = get_node(tmp_y,key);
    if(tmp_y==NIL) {
        root = tmp_z;
        root->color = Black;
        root->parent = NIL;
        return true;
    }else if(key>tmp_y->key){
        tmp_y->rchild = tmp_z;
    }else if(key<tmp_y->key){
        tmp_y->lchild = tmp_z;
    }
    rb_insert_fixup(root,tmp_z);
    return true;
}
bool rb_delete_fixup(rb_node* root,rb_node* node)
{
    rb_node *tmp_y;
    while(node->color==Black&&node!=root){
        if(node==node->parent->lchild){
            tmp_y = node->parent->rchild;
            if(tmp_y->color==Red){
                tmp_y->color = Black;
                node->parent->color = Red;
                left_rotate(root,node->parent);
                tmp_y = node->parent->rchild;
            }
            if(tmp_y->rchild->color==Black&&tmp_y->lchild->color==Black){
                tmp_y->color = Red;
                node = node->parent;
            }else{
                    if(tmp_y->rchild->color==Black){
                         tmp_y->color = Red;
                         tmp_y->lchild->color = Black;
                        right_rotate(root,tmp_y);
                        tmp_y = node->parent->rchild;
                    }
                    tmp_y->color = node->parent->color;
                    tmp_y->rchild->color = Black;
                    node->parent->color = Black;
                    left_rotate(root,node->parent);
                    node = root;
                    
            }
        }else if(node==node->parent->lchild){
            tmp_y = node->parent->lchild;
            if(tmp_y->color==Red){
                tmp_y->color = Black;
                node->parent->color = Red;
                right_rotate(root,node->parent);
                tmp_y = node->parent->lchild;
            }
            if(tmp_y->rchild->color==Black&&tmp_y->lchild->color==Black){
                tmp_y->color = Red;
                node = node->parent;
            }else{
                    if(tmp_y->lchild->color==Black){
                        tmp_y->color = Red;
                        tmp_y->rchild->color = Black;
                        left_rotate(root,tmp_y);
                        tmp_y = node->parent->lchild;
                    }
                    tmp_y->color = node->parent->color;
                    node->parent->color = Black;
                    tmp_y->lchild->color = Black;
                    right_rotate(root,node->parent);
            }
        }
    }
    node->color = Black;
    return true;
}     
rb_node* delete_node(rb_node* root,int key)
{
    
    rb_node *tmp_y,*tmp_x,*node;
    node = rb_search_node(root,key);
    if(node->lchild==NIL||node->rchild==NIL)
        tmp_y = node;
    else
        tmp_y = rb_tree_successor(node);
    tmp_x = tmp_y->lchild!=NIL?tmp_y->lchild:tmp_y->rchild;
    tmp_x->parent = tmp_y->parent;
    if(tmp_y->parent==NIL){
        root = tmp_x;
    }else if(tmp_y==tmp_y->parent->lchild){
        tmp_y->parent->lchild = tmp_x;
    }else if(tmp_y==tmp_y->parent->rchild){
        tmp_y->parent->rchild = tmp_x;
    }
    if(node!=tmp_y)
        node->key = tmp_y->key;
    if(tmp_y->color==Black){
        rb_delete_fixup(root,tmp_x); 
    }
    return tmp_y;
}

int main()
{
    rb_node *root;
    if(set_NIL()){
        cout<<"test"<<endl;
        root = get_node(NIL,11);
        root->color = Black;
    }
    int a[] = {2,1,7,5,8,14,15};
    for(int i=0;i<7;i++)
        insert_node(root,a[i]);
    rb_in_order(root);

    return 0;
}
