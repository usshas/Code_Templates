#include<iostream>
#include<algorithm>
using namespace std;

void selection_sort(int a[], int n)
{
    int i, j, min;
    for(i=0; i<n-1; i++)
    {
        min=i;
        for(j=i+1; j<n; j++)
        if(a[j]<a[min]) min=j;
        if(min==i) break;
        swap(a[i],a[min]);
    }
    return;
}

int main()
{
    int n;
    cin>>n;
    int a[n], i;
    for(i=0; i<n; i++)
    cin>>a[i];
    selection_sort(a, n);
    for(i=0; i<n; i++)
    cout<<a[i]<<" \n"[i==n-1];
    return 0;
}
/*
9    
29 72 98 13 87 66 52 51 36
*/