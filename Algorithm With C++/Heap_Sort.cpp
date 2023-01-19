#include<iostream>
using namespace std;
#define SZ 1000000
#define inf -999999999


struct Heap
{
    int heap[SZ], cnt;
    void InsertIntoHeap(int x);
    int DeleteRootHeap();
    void PrintHeap();
    Heap();
};

Heap:: Heap()
{
    cnt=0;
}

void Heap::InsertIntoHeap(int x)
{
    heap[++cnt]=x;
    int child=cnt, parent=child/2;
    while(parent)
    {
        if(heap[parent]<heap[child]) swap(heap[parent], heap[child]);
        else return;
        child=parent;
        parent/=2;
    }
    return;
}

int Heap::DeleteRootHeap()
{
    if(!cnt)
    {
        cout<<"Underflow!\n";
        return inf;
    }
    int max=heap[1];
    heap[1]=heap[cnt--];
    int parent=1, lchild=2, rchild=3;
    while(lchild<=cnt)
    {
        if(heap[lchild]>=heap[rchild])
        {
            if(heap[lchild]>heap[parent]) swap(heap[lchild], heap[parent]);
            else return max;
            parent=lchild;
            lchild=parent*2;
            rchild=lchild+1;
        }
        else
        {
            if(heap[rchild]>heap[parent] && rchild<=cnt) swap(heap[rchild], heap[parent]);
            //else if(heap[lchild]>heap[parent]) swap(heap[lchild], heap[parent]);
            else return max;
            parent=rchild;
            lchild=parent*2;
            rchild=lchild+1;
        }
    }
    return max;
}

void Heap::PrintHeap()
{
    for(int i=1; i<=cnt; i++)
    cout<<heap[i]<<" \n"[i==cnt];
    return;
}
void HeapSort(int *arr, int size)
{
    int i;
    Heap hp;
    for(i=0; i<size; i++)
    hp.InsertIntoHeap(arr[i]);
    for(i=0; i<size; i++)
    arr[size-i-1]=hp.DeleteRootHeap();
}
int main()
{
    int n;
    cin>>n;
    int i, a[n];
    for(i=0; i<n; i++)
    cin>>a[i];
    cout<<"Before HeapSort\n";
    for(i=0; i<n; i++)
    cout<<a[i]<<" \n"[i==n-1];
    HeapSort(a, n);
    cout<<"After HeapSort\n";
    for(i=0; i<n; i++)
    cout<<a[i]<<" \n"[i==n-1];
    return 0;
}

/*
9
2 15 3 8 6 11 13 7 16
*/