#include<iostream>
using namespace std;
#define SZ 10000000

long long tree[SZ];

void update(int index, long val, int position, int lst, int rst)
{
    if(lst==rst)
    {
        if(lst==position)
        tree[index]=val;
        return;
    }
    int mid=((lst+rst)>>1);
    if(position<=mid) update((index<<1), val, position, lst, mid);
    else update((index<<1)+1, val, position, mid+1, rst);
    tree[index]=tree[index<<1]+tree[(index<<1)+1];
}
int query(int index, int from, int to, int lst, int rst)
{
    if(from<=lst && to>=rst) return tree[index];
    if(from>rst || to<lst) return 0;
    long long sum=0;
    int mid=((lst+rst)>>1);
    sum+=query((index<<1), from, to, lst, mid);
    sum+=query((index<<1)+1, from, to, mid+1, rst);
    return sum;
}

int main()
{
    int n;
    cin>>n;
    long long a;
    int i;
    for(i=1; i<=n; i++)
    {
        cin>>a;
        update(1, a, i, 1, n);
    }
    int q, flag, from, to, val, position;
    cin>>q;
    for(i=0; i<q; i++)
    {
        cin>>flag;
        if(flag) {
            cin>>from>>to;
            cout<<query(1, from, to, 1, n)<<'\n';
        }
        else
        {
            cin>>val>>position;
            update(1, val, position, 1, n);
        }
    }
    return 0;
}