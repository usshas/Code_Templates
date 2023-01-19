#include<iostream>
#include<algorithm>
#include<vector>
#include<bits/stdc++.h>
#include<cstring>
using namespace std;

int BFS(vector<int> *adj, int *vis, int *path, int source, int destination)
{
    queue<pair<int,int>> q;
    q.push({source, 0});
    vis[source]=1;
    while(!q.empty())
    {
        int x=q.front().first, i, cost=q.front().second;
        //cout<<x<<", ";
        if(x==destination) return cost;
        q.pop();
        vis[x]=1;
        for(i=0; i<adj[x].size(); i++)
        {
            if(!vis[adj[x][i]]) 
            {
            	q.push({adj[x][i], cost+1});
            	vis[adj[x][i]]=1;
                path[adj[x][i]]=x;
            }
            	
        }
    }
    return -1;
}

int main()
{
    int n, m, source, destination;;
    cin>>n>>m;
    cin>>source>>destination;
    vector<int> adj[100];
    int vis[100], path[100];
    memset(vis, 0, sizeof(vis));
    memset(path, -1, sizeof(path));
    int i, x, y, mn=999999999, mx=-1;
    for(i=0; i<m; i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        mx=max(mx,max(y,x));
        mn=min(mn,min(y,x));
    }
    int ret=BFS(adj, vis, path, source, destination);
    cout<<"Cost for visiting "<<destination<<" from "<<source<<" = "<<ret<<'\n';
    vector<int> ans;
    x=destination;
    while(~x)
    {
        ans.push_back(x);
        x=path[x];
    }
    reverse(ans.begin(), ans.end());
    for(auto i: ans)
    cout<<i<<", ";
    cout<<'\n';
    return 0;
}