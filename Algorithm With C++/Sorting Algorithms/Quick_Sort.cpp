#include<iostream>
#include<algorithm>
using namespace std;

int partition(int arr[], int l, int h)
{
    int pivot=arr[h], i=l-1, j;
    for(j=l; j<h; j++)
    {
        if(arr[j]<=pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[++i], arr[h]);
    return i;
}

void qsort(int arr[], int l, int h)
{
    int p;
    if(l<h)
    {
        p=partition(arr, l, h);
        qsort(arr, l, p-1);
        qsort(arr, p+1, h);
    }
}

int main()
{
    int n;
    cin>>n;
    int a[n], i;
    for(i=0; i<n; i++)
    cin>>a[i];
    qsort(a, 0, n-1);
    for(i=0; i<n; i++)
    cout<<a[i]<<" \n"[i==n-1];
    return 0;
}
/*
7
10 80 30 90 40 50 70
*/