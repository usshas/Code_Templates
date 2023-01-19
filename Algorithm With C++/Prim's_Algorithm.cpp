#include<iostream>
#include<queue>
#include<vector>
using namespace std;
#define N 1010
vector<pair<int,int>> graph[N];
int parent[N];

void init(int n)
{
    for(int i=1; i<=n; i++)
    parent[i]=i;
}
int findpar(int n)
{
    if(n==parent[n]) return n;
    return parent[n]=findpar(parent[n]);
}
int Prims (int source, int n)
{
   priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
    int i;
    vector<pair<int, pair<int,int>>> ans;
    for(i=0; i<graph[source].size(); i++)
    {
        pq.push({graph[source][i].second, {source, graph[source][i].first}});
    }
    
    int s, p, q, u, v, w, result=0; 
    while(!pq.empty())
    {
        w=pq.top().first;
        p=pq.top().second.first;
        q=pq.top().second.second;
        pq.pop();
        u=findpar(p);
        v=findpar(q);
        s=findpar(source);
        if(u!=v)
        {
            ans.push_back({pq.top()});
            result+=w;
            source=u!=s?p:q;
            parent[v]=u;
            for(i=0; i<graph[source].size(); i++)
            {
                pq.push({graph[source][i].second, {source, graph[source][i].first}});
            }
        }
    }
    if(ans.size()!=n-1) 
    {
        cout<<"The initial graph may be disconnected.\n";
        return -1;
    }
    cout<<"Minimum spanning tree:\n";
    for(auto it:ans)
        cout<<"From: "<<it.second.first<<" To: "<<it.second.second<<" Cost: "<<it.first<<'\n';
    cout<<'\n';
    return result;
}

int main()
{
    int m, n, i, x, y, w;
    cin>>n>>m;
    for(i=0; i<m; i++)
    {
        cin>>x>>y>>w;
        graph[x].push_back({y, w});
        graph[y].push_back({x, w});
    }
    init(n);
    x=Prims(1, n);
    cout<<"Total cost: "<<x<<'\n';
    return 0;
}