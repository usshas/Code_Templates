#include<iostream>
#include<algorithm>
using namespace std;

void insertion_sort(int arr[], int n)
{
    int i, j;
    for(i=0; i<n; i++)
    {
        j=i+1;
        while(j-1>=0 && arr[j]<arr[j-1])
        {
            swap(arr[j], arr[j-1]);
            j--;
        }
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
    insertion_sort(a, n-1);
    for(i=0; i<n; i++)
    cout<<a[i]<<" \n"[i==n-1];
    return 0;
}

/*
7
7 8 5 2 4 6 3
*/