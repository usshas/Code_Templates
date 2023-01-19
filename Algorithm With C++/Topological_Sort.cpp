#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

vector<int> TopologicalSort(vector<int> graph[], int indegree[], int node, int mn)
{
    vector<int> list;
    queue<int> q;
    int i;
    for(i=0; i<node; i++)
    {
        if(!indegree[i] && i>=mn) q.push(i);
    }

    while(!q.empty())
    {
        int x=q.front();
        list.push_back(x);
        q.pop();
        for(i=0; i<graph[x].size(); i++)
        {
            indegree[graph[x][i]]--;
            if(!indegree[graph[x][i]]) q.push(graph[x][i]);
        } 
    }
    return list;
}

int main()
{
    int n,m, mn;
    cin>>n>>m;
    vector<int> v[200];
    int indegree[200];
    memset(indegree, 0, sizeof(indegree));
    int i, x, y;
    for(i=0; i<m; i++)
    {
        cin>>x>>y;
        v[x].push_back(y);
        indegree[y]++;
    }
    vector<int> ls=TopologicalSort(v, indegree, n, 1);
    cout<<"Order of graph: ";
    for(i=0; i<ls.size(); i++)
    cout<<ls[i]<<",\n"[i==ls.size()-1];
    return 0;
}