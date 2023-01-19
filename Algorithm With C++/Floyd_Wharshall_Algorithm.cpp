#include<iostream>
#include<vector>
using namespace std;

#define sz 1010
#define inf (1<<16)

int adj[sz][sz];
int Next[sz][sz];

void init(int n)
{
    int i, j;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(adj[i][j]) Next[i][j]=j;
            else
            {
                adj[i][j]=inf;
                Next[i][j]=-1;
            }
        }
    }
}

void printMatrix(int n)
{
    int i, j;
    for(i=0; i<n; i++)
    for(j=0; j<n; j++)
    cout<<adj[i][j]<<" \n"[j==n-1]; 
}

void FloydWharshall(int n)
{
    int i, j, k;
    for(k=0; k<n; k++)
    {
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                if(adj[i][j]>adj[i][k]+ adj[k][j])
                {
                    adj[i][j]=adj[i][k] + adj[k][j];
                    Next[i][j]=Next[i][k];
                }
            }
        }
    }
}

void findPath(int i, int j)
{
    
    while(i!=j)
    {
        cout<<i<<" ";
        i=Next[i][j];
    }
    cout<<j<<'\n';
    return;
}

int main()
{
    int n, m, x, y, w;
    cin>>n>>m;
    int i, j;
    for(i=0; i<m; i++)
    {
        cin>>x>>y>>w;
        adj[x][y]=w;
        adj[y][x]=w;
    }

    init(n);
    cout<<"Before running floyd_wharshall algorithm:\n";
    printMatrix(n);
    cout<<"\n\nAfter running floyd_wharshall algorithm:\n";
    FloydWharshall(n);
    printMatrix(n);
    //return 0;
    cout<<"\n\nEnter the number of paths you want to find: ";
    int p;
    cin>>p;
    for(i=0; i<p; i++)
    {
        cout<<"Enter the starting node: ";
        cin>>x;
        cout<<"Enter the ending node: ";
        cin>>y;
        cout<<"Path from node "<<x<<" to "<<y<<": ";
        findPath(x,y);
    }
    return 0;
}