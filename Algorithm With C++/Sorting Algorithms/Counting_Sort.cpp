#include<bits/stdc++.h>
using namespace std;
const int N=10;

void counting_sort(int arr[], int n)
{
    int i, count[N]={0};
    for(i=0; i<n; i++)
    count[arr[i]]++;
    for(i=0; i<N; i++)
    if(i-1!=-1) count[i]+=count[i-1];
    int sorted[n+1];
    for(i=1; i<=n; i++)
    {
        sorted[count[arr[i]]]=arr[i];
        count[arr[i]]--;
    }
    for(i=0; i<n; i++)
    arr[i]=sorted[i+1];
    return;
}

int main()
{
    int n;
    cin>>n;
    int a[n], i;
    for(i=0; i<n; i++)
    cin>>a[i];
    counting_sort(a, n);
    for(i=0; i<n; i++)
    cout<<a[i]<<" \n"[i==n-1];
    return 0;
}

/*
7
1 4 1 2 7 5 2*/