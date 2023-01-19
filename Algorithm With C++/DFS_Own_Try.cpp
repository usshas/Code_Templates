#include<bits/stdc++.h>
using namespace std;
vector<int> ls;
void DFS(vector<int> adj[], int *vis, int source)
{
    int x=source;
    
    if(!vis[x])
    {
        vis[x]=1;
        ls.push_back(x);
        int i;
        for(i=0; i<adj[x].size(); i++)
            if(!vis[adj[x][i]]) 
            {
                DFS(adj, vis, adj[x][i]);
            }
    }
    return;
}

int main()
{
    int m, n, x, y, i;
    cin>>m>>n;
    vector<int> v[100];
    int vis[100];
    memset(vis, 0, sizeof(vis));
    for(i=0; i<m; i++)
    {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    DFS(v, vis, 1);
    for(i=0; i<ls.size(); i++)
    cout<<ls[i]<<",\n"[i==ls.size()-1];
    return 0;
}