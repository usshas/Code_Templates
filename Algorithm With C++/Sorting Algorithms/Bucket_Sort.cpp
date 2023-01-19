#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void bucket_sort(float a[], int n)
{
    int i;
    vector<float> b[n];
    for(i=0; i<n; i++)
    b[(int)(a[i]*n)].push_back(a[i]);
    for(i=0; i<n; i++)
    sort(b[i].begin(), b[i].end());
    int index=0;
    for(i=0; i<n; i++)
    for(auto it:b[i]) a[index++]=it;
    return;
}

int main()
{
    int n;
    cin>>n;
    float a[n];
    int i;
    for(i=0; i<n; i++)
    cin>>a[i];
    bucket_sort(a,n);
    for(i=0; i<n; i++)
    cout<<a[i]<<" \n"[i==n-1];
    return 0;
}

/*
10
.78 .17 .39 .26 .72 .94 .21 .12 .23 .68
*/