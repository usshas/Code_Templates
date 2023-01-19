#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int getmax(string s[], int n)
{
    int i, m=0, n;
    for(i=0; i<n; i++)
    {
        n=s[i].size();
        m=max(m, n);
    }
    return m;
}

int main()
{
    int n, i;
    cin>>n;
    string s[n];
    for(i=0; i<n; i++)
    cin>>s[i];
    return 0;
}