#include<bits/stdc++.h>
using namespace std;

const int N=1010;
vector<int> g[N];
int vis[N], itime[N], low[N];

void dfs(int s, int p, int t)
{
    vis[s]=1;
    itime[s]=low[s]=t;
    for(auto it: g[s])
    {
        if(it==p) continue;
        if(!vis[it]) 
        {
            dfs(it, s, t+1);
            if(itime[s]<low[it]) cout<<s<<" & "<<it<<" is a bridge.\n";
            low[s]=min(low[s],low[it]);
        }
        else low[s]=min(low [s], low[it]);
    }
    return;
}

void findBRIDGE(int n)
{
    dfs(1, -1, 1);
    return;
}

int main()
{
    int n, m, i, x, y;
    cin>>n>>m;
    for(i=0; i<m; i++)
    {
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    findBRIDGE(n);
    return 0;
}

/*
12 14
1 2
2 3
3 4
4 1
4 5
5 6
6 7
7 8
8 9
9 6
8 10
10 11
11 12
12 10
8 & 10 is a bridge.
5 & 6 is a bridge.
4 & 5 is a bridge.
*/