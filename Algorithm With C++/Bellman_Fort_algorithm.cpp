#include<iostream>
#include<vector>
using namespace std;

struct node{
    int u, v, wt;
    node(int first, int second, int weight)
    {
        u=first;
        v=second;
        wt=weight;
    }
};

int main()
{
    int n, m, x, y, wt, i;
    cin>>n>>m;
    vector<node> edges;
    for(i=0; i<m; i++)
    {
        cin>>x>>y>>wt;
        edges.push_back(node(x,y,wt));
    }
    int inf=(1<<30);
    vector<int> cost(n, inf);
    int src, dest;
    cin>>src>>dest;
    cost[src]=0;
    for(i=1; i<=n-1; i++)
    {
        for(auto it:edges)
        {
            if(cost[it.u] + it.wt<cost[it.v])
            cost[it.v]=cost[it.u] + wt;
        }
    }
    bool flag=true;
    for(auto it:edges)
    {
        if(cost[it.u] + it.wt<cost[it.v])
        {
            cout<<"Negative cycle.\n";
            flag=false;
            break;
        }
    }

    if(flag)
    {
        cout<<"Cost from source to:\n";
        for(i=1; i<=n; i++)
        {
            cout<<i<<": "<<cost[i]<<"\n";
        }
    }
    return 0;
}