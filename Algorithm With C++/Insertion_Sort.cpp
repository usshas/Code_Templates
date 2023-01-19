#include<iostream>
using namespace std;

void InsertionSort(int *arr, int size)
{
    int i, j, mn=0;
    for(i=1; i<size; i++)
    {
        mn=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>mn)
        {
            arr[j+1]=arr[j];
            j--;
            arr[j+1]=mn;
        }
    }
    return;
}


int main()
{
    int n;
    cin>>n;
    int arr[n], i;
    for(i=0; i<n; i++)
    cin>>arr[i];
    InsertionSort(arr, n);
    cout<<"Sorted Array: ";
    for(i=0; i<n; i++)
    cout<<arr[i]<<" \n"[i==n-1];
    return 0;
}