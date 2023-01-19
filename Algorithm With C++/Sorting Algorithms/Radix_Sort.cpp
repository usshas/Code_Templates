#include<iostream>
#include<algorithm>
using namespace std;

int getmax(int a[], int n)
{
    int m=0, i;
    for(i=0; i<n; i++)
    m=max(m, a[i]);
    return m;
}

void count_sort(int a[], int n, int pos)
{
    int count[10]={0}, ans[n], i;
    for(i=0; i<n; i++)
    count[(a[i]/pos)%10]++;
    for(i=1; i<10; i++)
    count[i]+=count[i-1];
    for(i=n-1; i>=0; i--)
    ans[--count[(a[i]/pos)%10]]=a[i];
    for(i=0; i<n; i++)
    a[i]=ans[i];
    return;
}

void radix_sort(int a[], int n)
{
    int m=getmax(a,n), pos;
    for(pos=1; m/pos; pos*=10)
    count_sort(a, n, pos);
    return;
}

int main()
{
    int n;
    cin>>n;
    int a[n], i;
    for(i=0; i<n; i++)
    cin>>a[i];
    radix_sort(a,n);
    for(i=0; i<n; i++)
    cout<<a[i]<<" \n"[i==n-1];
    return 0;
}