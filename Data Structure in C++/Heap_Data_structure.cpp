#include<iostream>
using namespace std;
#define SZ 1000000
#define inf 999999999999999999
struct Heap{
    long long heap[SZ];
    void InsertIntoHeap(long long x);
    long long DeleteRootHeap();
    int cnt;
    void PrintHeap();
    Heap();
};

Heap:: Heap()
{
    cnt=0;
}

void Heap::InsertIntoHeap(long long x)
{
    heap[++cnt]=x;
    int child=cnt, parent=child/2;
    while(parent>0)
    {
        if(heap[parent]<heap[child])
        swap(heap[parent], heap[child]);
        else return;
        child=parent;
        parent/=2;
    }
    return;
}


long long Heap::DeleteRootHeap()
{
    if(!cnt) 
    {
        cout<<"Underflow!\n";
        return inf;
    }
    long long max=heap[1];
    heap[1]=heap[cnt--];
    int parent=1, lchild=parent*2, rchild=lchild+1, mxind;
    while(lchild<=cnt)
    {
        if(rchild<=cnt) mxind=heap[lchild]>heap[rchild]?lchild:rchild;
        else mxind=lchild;
        if(heap[mxind]>heap[parent]) swap(heap[mxind], heap[parent]);
        else return max;
        parent=mxind;
        lchild=parent*2;
        rchild=lchild+1;
    }
    return max;
}

void Heap:: PrintHeap()
{
    int i;
    for(i=1; i<=cnt; i++)
    cout<<heap[i]<<" \n"[i==cnt];
    return;
}

void HeapSort(int a[], int n, int ascending)
{
    Heap hp;
    int i;
    for(i=0; i<n; i++)
    hp.InsertIntoHeap(a[i]);
    for(i=0; i<n; i++)
    a[ascending?n-i-1:i]= hp.DeleteRootHeap();
}

int main()
{
    int n, i;
    cin>>n;
    long long a;
    Heap x;
    for(i=0; i<n; i++)
    {
        cin>>a;
        x.InsertIntoHeap(a);
    }
    x.PrintHeap();
    for(i=0; i<n; i++)
    {
        x.DeleteRootHeap();
        x.PrintHeap();
    }
    return 0;
}

/*
10
9 1 2 8 3 7 4 6 5 10
*/


















