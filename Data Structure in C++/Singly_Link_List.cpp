#include<iostream>
using namespace std;

struct node{
    int val;
    node *next;
    node(int);
};

node::node(int x)
{
    val=x;
    next=NULL;
}

struct SinglyLinkList{
    node *head, *tail;
    SinglyLinkList();
    int enqueue(int data);
    int dequeue();
    int count();
    void insertafterhead(int data);
    void insertbeforetail(int data);
    void insertbeforevalue(int value, int insert);
    void insertaftervalue(int value, int insert);
    void insertbeforeposition(int position, int insert);
    void insertafterposition(int position, int insert);
    void sortedinsert(int data);
    bool is_sorted();
    int valueathead();
    int valueattail();
    void display();
    void reverse();
    void recursivereverse(node*);
    void callreverse();
    int deletehead();
    int deletetail();
    int deleteatposition(int position);
    int deleteafterhead();
    int deletebeforetail();
};

SinglyLinkList::SinglyLinkList()
{
    head=NULL;
    tail=NULL;
}

int SinglyLinkList::enqueue(int data)
{
    node *cur= new node(data);
    if(!head)
    {
        cur->val=data;
        cur->next=tail;
        head=cur;
        tail=cur;
        return tail->val;
    }
    cur->val=data;
   // cur->next=NULL;
    tail->next=cur;
    tail=cur;
   // tail->next=NULL;
    return tail->val;
}

int SinglyLinkList::dequeue()
{
   if(!head)
   {
    cout<<"Underflow\n";
    return -1;
   }
   node *temp=head;
   int x=temp->val;
   if(temp==tail)
   {
    head=NULL;
    tail=NULL;
    delete temp;
    return x;
   }
    head=head->next;
    delete temp;
    return x;
}

int SinglyLinkList::count()
{
    node *p=head;
    int cnt=0;
    while(p)
    {
        cnt++;
        p=p->next;
    }
    return cnt;
}

void SinglyLinkList::insertafterhead(int data)
{
    node *cur=new node(data);
    if(!head)
    {
        head=cur;
        tail=cur;
        return;
    }
    if(head==tail)
    {
        head->next=cur;
        tail=cur;
        return;
    }
    cur->next=head->next;
    head->next=cur;
    return;
}

void SinglyLinkList::insertbeforetail(int data)
{
    node *cur=new node(data);
    if(!head)
    {
        head=cur;
        tail=cur;
        return;
    }
    if(head==tail)
    {
        tail->next=cur;
        tail=cur;
        return;
    }
    node *p=head->next, *q=head;
    while(p!=tail)
    {
        p=p->next;
        q=q->next;
    }
    q->next=cur;
    cur->next=tail;
    return;
}

void SinglyLinkList::display()
{
    node *cur=head;
    if(!cur)
    {
        cout<<"List is empty\n";
        return;
    }
    while(cur)
    {
        cout<<cur->val<<" ";
        cur=cur->next;
    }
    cout<<'\n';
    return;
}

void SinglyLinkList::insertbeforevalue(int value, int insert)
{  
    if(!head)
    {
        cout<<"Value not found\n";
        return;
    }
    node *cur=new node(insert);
    if(head==tail)
    {
        if(head->val==value)
        {
            cur->next=head;
            head=cur;
            return;
        }
        cout<<"Value not found\n";
        return;
    }
    if(head->val==value)
    {
        cur->next=head;
        head=cur;
        return;
    }
    node *p=head;
    while(p!=tail->next)
    {
        if(p->next->val==value) break;
    }
    if(!p)
    {
        cout<<"Value not found\n";
        return;
    }
    cur->next=p->next;
    p->next=cur;
    return;
}

void SinglyLinkList::insertaftervalue(int value, int insert)
{
    if(!head)
    {
        cout<<"List is Empty.\n";
        return;
    }
    node *cur=new node(insert);
    cur->val=insert;
    if(head==tail)
    {
        if(head->val!=value)
        {
            cout<<"Value not found.\n";
            return;
        }
        tail->next=cur;
        tail=cur;
        return;
    }
    if(head->val==value)
    {
        cur->next=head->next;
        head->next=cur;
        return;
    }
    node *p=head;
    while(p)
    {
        if(p->val==value) break;
        p=p->next;
    }
    if(!p)
    {
        cout<<"Value not found\n";
        return;
    }
    cur->next=p->next;
    p->next=cur;
    return;
}

void SinglyLinkList::insertbeforeposition(int position, int insert)
{
    if(position>count())
    {
        cout<<"Underflow!.\n";
        return;
    }
    node *cur=new node(insert);
    cur->val=insert;
    if(position==1)
    {
        cur->next=head;
        head=cur;
        return;
    }
    int i=1;
    node *p=head;
    while(i<position-1)
    {
        p=p->next;
        i++;
    }
    cur->next=p->next;
    p->next=cur;
    return;
}

void SinglyLinkList::insertafterposition(int position, int insert)
{
    if(position>count())
    {
        cout<<"Overflow!.\n";
        return;
    }
    int i=1;
    node *cur=new node(insert);
    node *p=head;
    while(i<position)
    {
        p=p->next;
        i++;
    }
    if(p==tail)
    {
        p->next=cur;
        tail=cur;
        return;
    }
    cur->next=p->next;
    p->next=cur;
    return; 
}


int SinglyLinkList::deletehead()
{
    if(!head)
    {
        cout<<"Underflow!\n";
        return -1;
    }
    node *temp=head;
    int x=temp->val;
    if(head==tail)
    {
        head=NULL;
        tail=NULL;
        return x;
    }
    head=head->next;
    delete temp;
    return x;
}

int SinglyLinkList::deletetail()
{
    if(!head)
    {
        cout<<"Underflow!\n";
        return -1;
    }
    node *temp=head, *cur=head->next;
    int x;
    if(head==tail)
    {
        head=NULL;
        tail=NULL;
        x=temp->val;
        delete temp;
        return x;
    }
    while(cur!=tail)
    {
        cur=cur->next;
        temp=temp->next;
    }
    x=cur->val;
    tail=temp;
    tail->next=NULL;
    delete cur;
    return x;
}


int SinglyLinkList::deleteatposition(int position)
{
    if(position>count())
    {
        cout<<"List is too sort.\n";
        return -1;
    }
    node *temp=head, *cur=head->next;
    int x, i=1;
    if(head==tail)
    {
        x=head->val;
        head=NULL;
        tail=NULL;
        delete temp;
        return x;
    }
    if(position==1)
    {
        x=head->val;
        head=head->next;
        delete temp;
        return x;
    }
    while(i<position-1)
    {
        cur=cur->next;
        temp=temp->next;
        i++;
    }
    if(position==count())
    {
        tail=temp;
        tail->next=NULL;
        x=cur->val;
        delete cur;
        return x;
    }
    temp->next=cur->next;
    x=cur->val;
    delete cur;
    return x;
}

int SinglyLinkList::deleteafterhead()
{
    if(!head || head==tail)
    {
        cout<<"Underflow!\n";
        return -1;
    }
    node *temp=head->next;
    int x=temp->val;
    if(head->next==tail)
    {
        tail=head;
        tail->next=NULL;
        delete temp;
        return x;
    }
    head->next=temp->next;
    delete temp;
    return x;
}

int SinglyLinkList::deletebeforetail()
{
    if(!head || head==tail)
    {
        cout<<"Underflow!\n";
        return -1;
    }
    node *temp=head, *cur=head->next;
    int x;
    if(head->next==tail)
    {
        head=tail;
        x=temp->val;
        delete temp;
        return x;
    }

    while(cur->next!=tail)
    {
        temp=temp->next;
        cur=cur->next;
    }
    temp->next=tail;
    tail->next=NULL;
    x=cur->val;
    delete cur;
    return x;
}

void SinglyLinkList::  sortedinsert(int data)
{
    struct node *cur=new node(data);
    if(!head)
    {
        head=tail=cur;
        return;
    }
    if(cur->val<head->val)
    {
        cur->next=head;
        head=cur;
        return;
    }
    if(cur->val>tail->val)
    {
        tail->next=cur;
        tail=cur;
        return;
    }

    node *p=head; 
    while(p)
    {
        if(p->next->val>cur->val) break;
        p=p->next;
    }
    cur->next=p->next;
    p->next=cur;
    return;
}

bool SinglyLinkList::is_sorted()
{
    if(!head || head==tail)
    return true;
    node *p=head->next, *q=head;
    while(p)
    {
        if(q->val>p->val) return false;
        p=p->next;
        q=q->next;
    }
    return true;
}

int SinglyLinkList::valueathead()
{
    if(!head)
    {
        cout<<"List is empty\n";
        return -1;
    }
    return head->val;
}

int SinglyLinkList::valueattail()
{
    if(!tail)
    {
        cout<<"List is empty\n";
        return -1;
    }
    return tail->val;
}

void SinglyLinkList:: reverse()
{
    node *now=head, *nowprev=NULL, *nowaf=NULL;
    tail=head;
    while(now)
    {
        //now=now->next;
        nowaf=now->next;
        now->next=nowprev;
        nowprev=now;
        now=nowaf;
    } 
    head=nowprev;
}

void SinglyLinkList:: recursivereverse(node* now)
{
    node *nowprev=NULL, *nowaf=NULL;
    if(!now->next)
    {
        head=now;
        return;
    }
    recursivereverse(now->next);
    nowaf=now->next;
    nowaf->next=now;
    now->next=NULL;
    
}

void SinglyLinkList:: callreverse()
{
    recursivereverse(head);
}







int main()
{
    SinglyLinkList *x= new SinglyLinkList();
    
    x->enqueue(18);
    x->enqueue(19);
    x->enqueue(22);
    x->enqueue(20);
   /*
    cout<<x->valueathead()<<'\n';
    cout<<x->valueattail()<<"\n";
    x->display();
    x->reverse();
    x->display();
    cout<<x->valueathead()<<'\n';
    cout<<x->valueattail()<<"\n";
    x->reverse();
    x->display();
    cout<<x->valueathead()<<'\n';
    cout<<x->valueattail()<<"\n";
    x->callreverse();
    x->display();
    */
   x->enqueue(89);
   x->display();
   //cout<<x->is_sorted()<<'\n';
    return 0;
}



