#include<bits/stdc++.h>
using namespace std;
const int N=10e5+10;
int parent[N]; 
int Size[N];

void make(int v)
{
    parent[v]=v;
    Size[v]=1;
    return;
}

int find(int v)
{
    if(v==parent[v]) return v;
    return parent[v]=find(parent[v]);
}

void Union(int a, int b)
{
    a=find(a);
    b=find(b);
    if(a!=b) {
        if(Size[a]<Size[b]) swap(a,b);
        Size[a]+=Size[b];
        parent[b]=a;
    }
    return;
}

int main()
{

    return 0;
}
