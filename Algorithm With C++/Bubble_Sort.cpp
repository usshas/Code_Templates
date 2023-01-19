#include<iostream>
using namespace std;

void BubbleSort(int *arr, int size)
{
    for(int i=0; i<size; i++)
    {
        int flag=1;
        for(int j=0; j<size-1; j++)
        {
            if(arr[j]>arr[j+1]) 
            {
                swap(arr[j],arr[j+1]);
                flag=0;
            }
        }
        if(flag) break;
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
    BubbleSort(arr, n);
    cout<<"Sorted Array:";
    for(i=0; i<n; i++)
    cout<<arr[i]<<" \n"[i==n-1];
    return 0;
}