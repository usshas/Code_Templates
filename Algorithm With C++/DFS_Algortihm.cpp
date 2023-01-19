#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<stack>
using namespace std;

struct DFS{
    void dfs(int node, vector<int> adj[], int vis[], vector<int> &ls)
    {
        vis[node]=1;
        ls.push_back(node);
        for(auto it: adj[node])
        if(!vis[it]) dfs(it, adj, vis, ls);
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[], int start)
    {
        int vis[V]={0};
        vector<int> ls;
        dfs(start, adj, vis, ls);
        return ls;
    }
};


int main()
{
    int n, m, i, x, y;
    cin>>n>>m;
    vector<int> v[2000];
    for(i=0; i<m; i++)
    {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    DFS* xx=new DFS;
    vector<int> path=xx->dfsOfGraph(n, v, 1);
    for(i=0; i<path.size(); i++)
    cout<<path[i]<<" \n"[i==path.size()-1];
    return 0;
}


/*
#include <bits/stdc++.h>
using namespace std;
vector<long long int>edges[100];
vector<long long int>result;
long long int visited[1000],c=0;


void dfs(long long int s)
{
    long long int x,y,z;

    if(visited[s]==0)
    {
        visited[s]=1;
        for(x=0;x<edges[s].size();x++)
        {
            z=edges[s][x];
            if(visited[z]==0)
            {
                result.push_back(z);
                dfs(z);

            }

        }
    }

}

int main()
{
    long long int i,j,k,l,u,v,n,e;
    cin>>n>>e;
    for(i=1;i<=e;i++)
    {
        cin>>u>>v;
        if(i==1)
        {
            l=u;
        }
        edges[u].push_back(v);
        edges[v].push_back(u);

    }
    memset(visited,0, sizeof visited);
    result.push_back(l);

    dfs(l) ;
    cout<<"\nVisit Sequence= ";
    for(k=0;k<result.size();k++)
    {
        cout<<result[k]<<",\n"[k==result.size()-1];
    }


    return 0;
}
*/