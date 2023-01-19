#include<iostream>
#include<algorithm>
using namespace std;

bool binary_search(int *arr, int key, int size)
{
    int l=0, r=size-1;
    while(l<=r)
    {
        int mid=l+(r-l)/2;
        if(key==arr[mid]) return true;
        else if(key>arr[mid]) l=mid+1;
        else r=mid-1;
    }
    return false;
}

int main()
{
    int n, q, key;
    cin>>n;
    int a[n], i;
    for(i=0; i<n; i++)
    cin>>a[i];
    sort(a, a+n);
    cin>>q;
    while(q--)
    {
        cin>>key;
        cout<<binary_search(a, key, n)<<"\n";
    }
    return 0;
}