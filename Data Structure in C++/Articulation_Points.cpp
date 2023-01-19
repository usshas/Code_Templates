#include<bits/stdc++.h>
using namespace std;

const int N=1010;
vector<int> g[N];
int vis[N], itime[N], low[N], ap[N], timer=1;

void dfs(int s, int p)
{
    vis[s]=1;
    itime[s]=low[s]=timer++;
    for(auto it: g[s])
    {
        if(it==p) continue;
        if(!vis[it])
        {
            dfs(it, s);
            low[s]=min(low[s], low[it]);
            if(low[it]>=itime[s]) ap[s]=1;
        }
        else low[s]= min(low [s], itime[it]);
    }
    return;
}

void findPOINT(int n)
{
    dfs(0,-1);
    int i;
    for(i=0; i<n; i++)
    if(ap[i]) cout<<i<<" is an articulation point.\n";
    return;
}

int main()
{
    int m, n, i, x, y;
    cin>>n>>m;
    for(i=0; i<m; i++)
    {
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    findPOINT(n);
    return 0;
}
/*
7 8
0 1
0 2
0 3
2 3
2 4
2 5
4 6
5 6
*/