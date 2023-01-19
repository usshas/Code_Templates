#include<bits/stdc++.h>
using namespace std;

const int N=1010;
vector<int> g[N], rg[N], dag[N], v;
vector<vector<int>> scc;
bool vis[N];
int par[N];
stack<int> st;

void DFS1(int s)
{
    vis[s]=true;
    for(auto it: g[s]) if(!vis[it]) DFS1(it);
    st.push(s);
}

void DFS2(int s, int p)
{
    v.push_back(s);
    vis[s]=false;
    par[s]=p;
    for(auto it: rg[s]) if(vis[it]) DFS2(it, p);
    return;
}

int findSCC(int n)
{
    int i, x;
    for(i=0; i<n; i++)
    if(!vis[i]) DFS1(i);

    i=0;
    while(!st.empty())
    {
        x=st.top();
        st.pop();
        if(vis[x])
        {
            DFS2(x, i++);
            scc.push_back(v);
            v.clear();
        }
    }
    return i;
}

void findDAG(int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        for(auto it: g[i])
        {
            if(par[it]!=par[i])  dag[par[i]].push_back(it);
        }
    }
}
int main()
{
    int n, m, i, x, y;
    cin>>n>>m;
    for(i=0; i<m; i++)
    {
        cin>>x>>y;
        g[x].push_back(y);
        rg[y].push_back(x);
    }

    m=findSCC(n);
    cout<<"Total component(s) in SCC: "<<m<<'\n';
    for(i=0; i<scc.size(); i++)
    {
        cout<<"SCC "<<i+1<<":\t";
        for(auto it: scc[i]) cout<<it<<" ";
        cout<<'\n';
    }
    cout<<"Total node(s) in DAG: "<<m<<'\n';
    for(i=0; i<m; i++)
    {
        cout<<"From SCC "<<i<<" to: ";
        for(auto it: dag[i]) cout<<it<<" ";
        cout<<'\n';
    }
    for(i=0; i<n; i++)
    cout<<par[i]<<" \n"[i==n-1];
    return 0;
}