#include<iostream>
using namespace std;
#define SZ 10000000

long long tree[SZ];

long long query(int ind)
{
    long long sum=0;
    while(ind)
    {
        sum+=tree[ind];
        ind-=(ind&-ind);
    }
    return sum;
}

void update(long long val, int ind, int size)
{

    while(ind<=size)
    {
        tree[ind]+=val;
        ind+=(ind&-ind);
    }
    return;
}

int main()
{
    int n, i;
    cin>>n;
    long long a;
    for(i=0; i<n; i++)
    {
        cin>>a;
        update(a, i+1, n);
    }
    int q;
    cin>>q;
    while(q--)
    {
        int flag, mn, mx, ind;
        cin>>flag;
        if(flag)
        {
            cin>>mn>>mx;
            cout<<query(mx) - query(mn-1)<<'\n';
        }
        else
        {
            cin>>ind>>a;
            a-=tree[ind];
            update(a, ind, n);
        }
    }
    return 0;
}