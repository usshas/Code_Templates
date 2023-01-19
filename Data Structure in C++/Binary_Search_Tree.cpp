#include<iostream>
using namespace std;

struct node{
    int val;
    node *left, *right, *parent;
    node(int x);
};

node::node(int x)
{
    val=x;
    left=right=parent=NULL;
}

struct BST{
    node *root;

    ///Constructor
    BST();

    ///Utility Functions
    node* left_or_right(node* now, int x);
    void print(node* trav, int flag);
    node* find_del(int x);
    node* find_successor(node* temp);

    ///Global Functions
    void insert(int x);
    void del(int x);
    bool find(int x);
    void pre_taverse();
    void in_traverse();
    void post_traverse();
};

BST::BST()
{
    root=NULL;
}

 node* BST:: left_or_right(node* now, int x)
 {
    if(x<now->val) now=now->left;
    else now=now->right;
    return now;
 }

void BST:: insert(int x)
{
    node *cur= new node(x);
    if(!root)
    {
        root=cur;
        return;
    }
    node* now=root, *next;
    next=left_or_right(now, x);
    while(next)
    {
        now=next;
        next=left_or_right(next, x);
    }
    if(x<now->val) now->left=cur;
    else now->right=cur;
    cur->parent=now;
    /*
    cout<<"Insert after= "<<now->val<<"\n";
    cout<<"cur->val= "<<To be inserted= <<"\n\n";
    cout<<"cur= "<<cur<<"\n";
    (now->left) cout<<"now->left= "<<now->left<<"\n";
    (now->right) cout<<"now->right= "<<now->right<<"\n\n";
    cout<<"now= "<<now<<'\n';
    cout<<"cur->parent= "<<cur->parent<<"\n\n\n";
    */
    return;
}


node* BST:: find_del(int x)
{
    node *search=root;
    while(search)
    {
        //cout<<search->val<<" ";
        if(search->val==x) return search;
        search=left_or_right(search, x);
    }
    return search;
}

node* BST:: find_successor(node *temp)
{
    while(temp->left)
    { 
        
        temp=temp->left;
    }
   // cout<<temp->val<<"\n";
    return temp;
}


void BST:: del(int x)
{
    node *delposition=find_del(x);
    if(!delposition)
    {
        cout<<"Value isn't found.\n";
    }
    node *temp=delposition;
    if(delposition->right)
    {
        temp=find_successor(delposition->right);
        if(temp->right)
        {
            delposition->val=temp->val;
            temp->val=temp->right->val;
            temp=temp->right;
            temp->parent->right=NULL;
            temp->parent=NULL;
            delete temp;
            return;
        }
        delposition->val=temp->val;
        temp->parent->right=NULL;
        temp->parent=NULL;
        delete temp;
        return;
    }
    if(temp->left)
    {
        temp->left->parent=temp->parent;
        temp->parent->left=temp->left;
        temp->parent=NULL;
        temp->left=NULL;
        delete temp;
        return;
    }
    if(temp->parent->left->val==temp->val)
    {
        temp->parent->left=NULL;
        temp->parent=NULL;
        delete temp;
        return;
    }
    temp->parent->right=NULL;
    temp->parent=NULL;
    delete temp;
    return;
}


bool BST:: find(int x)
{
    node *search=root;
    while(search)
    {
        if(search->val==x) return true;
        search=left_or_right(search, x);
    }
    return false;
}


void BST:: print(node *trav, int flag)
{
    if(!trav) return;
    if(flag==1) cout<<trav->val<<" ";
    print(trav->left, flag);
    if(flag==-1) cout<<trav->val<<" ";
    print(trav->right, flag);
    if(!flag) cout<<trav->val<<" ";
}

void BST::pre_taverse()
{
    print(root, 1);
    cout<<'\n';
    return;
}

void BST::in_traverse()
{
    print(root, -1);
    cout<<'\n';
    return;
}

void BST::post_traverse()
{
    print(root, 0);
    cout<<'\n';
    return;
}

int main()
{
    BST *x= new BST;
    x->insert(13);
    x->insert(5);
    x->insert(3);
    x->insert(4);
    x->insert(1);
    x->insert(9);
    x->insert(8);
    x->insert(12);
    x->insert(6);
    x->insert(10);
    x->insert(7);
    x->insert(14);
    x->pre_taverse();
   // x->in_traverse();
   // x->post_traverse();
    x->del(1);
    x->pre_taverse();
   // cout<<x->find(20)<<'\n';
    return 0;
}