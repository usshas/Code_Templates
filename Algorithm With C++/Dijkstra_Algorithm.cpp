#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
const int inf=1<<30; 
#define SZ 1010
vector<pair<int,int>> g[SZ];
int cost[SZ];
vector<int> ls;

void dijkstra(int source, int destination)
{
    cost[source]=0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    q.push({0, source});
    ls.push_back(source);
    while(!q.empty())
    {
        int x=q.top().second, ct=q.top().first;
        q.pop();
        for(int i=0; i<g[x].size(); i++)
        {
            if(ct+g[x][i].second<cost[g[x][i].first])
            {
                cost[g[x][i].first]=ct+g[x][i].second;
                q.push({cost[g[x][i].first], g[x][i].first});
                if(ls[ls.size()-1]!=x) ls.push_back(x);
            }
        }
    }
    ls.push_back(destination);
    return;
}

int main()
{
    int n, m, i, x, y, ct;
    cin>>n>>m;
    for(i=0; i<m; i++)
    {
        cin>>x>>y>>ct;
        g[x].push_back({y,ct});
        g[y].push_back({x,ct});
    }
    for(i=0; i<=n; i++)
    cost[i]=1<<30;
    cin>>x>>y;
    dijkstra(x, y);
    cout<<"Minimum cost to travel from "<<x<<" to "<<y<<" is: "<<cost[y]<<"\n";
    cout<<"Path: ";
    for(i=0; i<ls.size(); i++)
    cout<<ls[i]<<",\n"[i==ls.size()-1];
    ls.clear();
    for(i=0; i<=n; i++)
    g[i].clear();
    return 0;
}
