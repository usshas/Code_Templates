#include<iostream>
#include<algorithm>
using namespace std;

bool ternary_search(int *arr, int key, int size)
{
    int l=0, r=size-1, mid1, mid2;
    while(l<=r)
    {
        mid1=l+(r-l)/3;
        mid2=r-(r-l)/3;
        if(key==arr[mid1]) return true;
        if(key==arr[mid2]) return true;
        if(key<arr[mid1]) r=mid1-1;
        else if(key>arr[mid2]) l=mid2+1;
        else 
        {
            l=mid1+1;
            r=mid2-1;
        }
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
        cout<<ternary_search(a, key, n)<<'\n';
    }
    return 0;
}