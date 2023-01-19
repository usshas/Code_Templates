#include<iostream>
using namespace std;

struct node{
    int val;
    node *next;
    node();
};
node::node()
{
    next=NULL;
}

struct Stack{
    node  *top;
    int push(int data);
    int pop();
    int Top();
    Stack();
};

Stack::Stack()
{
    top=NULL;
}

int Stack::push(int data)
{
    node *cur=new node;
    cur->val=data;
    if(!top)
    {
        top=cur;
        top->next=NULL;
        return cur->val;
    }
    cur->next=top;
    top=cur;
    return cur->val;
}

int Stack::pop()
{
    if(!top)
    {
        cout<<"Underflow!\n";
        return -1;
    }

    node *temp=top;
    int x=temp->val;
    top=top->next;
    delete temp;
    return x;
}

int Stack::Top()
{
    if(!top)
    {
        cout<<"Stack is empty\n";
        return -1;
    }
    return top->val;
}







int main()
{
    Stack *x= new Stack;
    //cout<< x->pop()<<'\n';
    //cout<<x->Top()<<"\n";
    cout<<x->push(89)<<"\n";
    cout<<x->push(43)<<"\n";
    cout<<x->push(44)<<"\n";
    cout<<x->push(51)<<"\n";
    cout<<x->push(96)<<"\n\n";
    cout<< x->pop()<<'\n';
    cout<<x->Top()<<"\n";
    cout<< x->pop()<<'\n';
    cout<<x->Top()<<"\n";
    cout<< x->pop()<<'\n';
    cout<<x->Top()<<"\n";
    cout<< x->pop()<<'\n';
    cout<<x->Top()<<"\n";
    cout<< x->pop()<<'\n';
    cout<<x->Top()<<"\n";
    cout<< x->pop()<<'\n';
    cout<<x->Top()<<"\n";
   return 0;
}