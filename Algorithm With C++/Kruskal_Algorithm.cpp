#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int N=1010;
vector<pair<int,pair<int,int>>> graph;
int parent[N];

void init(int n)
{
    int i;
    for(i=1; i<=n; i ++)
    parent[i]=i;
}

int find_par(int n)
{
    if(parent[n]==n) return n;
    return parent[n]=find_par(parent[n]);
}

int Kruskal(int n)
{
    int u, v, w, result=0, p, q;
    vector<pair<int,pair<int,int>>> ans, edges;
    for(auto it:graph)
    edges.push_back(it);
    sort(edges.begin(), edges.end());
    for(auto it:edges)
    {
        p=it.second.first;
        q=it.second.second;
        w=it.first;
        u=find_par(p);
        v=find_par(q);
        if(u!=v)
        {
            result+=w;
            ans.push_back(it);
            parent[v]=u;
        }
    }
    if(ans.size()!=n-1)
    {
        cout<<"The graph seems disconnected.\n";
        return -1;
    }
    for(auto it:ans)
    cout<<"From: "<<it.second.first<<" To: "<<it.second.second<<" Cost: "<<it.first<<'\n';
    
    return result;
}

int main()
{
    int n, m, i, x, y, w;
    cin>>n>>m;
    for(i=0; i<m; i++)
    {
        cin>>x>>y>>w;
        graph.push_back({w,{x,y}});
        graph.push_back({w,{y,x}});
    }
    init(n);
    x=Kruskal(n);
    cout<<"Total Cost: "<<x<<'\n';
    return 0;
}