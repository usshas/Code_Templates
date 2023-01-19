#include<iostream>
using namespace std;

int* Merge(int *a, int left, int mid, int right)
{
    int l=mid-left+1, r=right-mid;
    int lt[l], rt[r], i;
    for(i=0; i<l; i++)
    lt[i]=a[i+left];
    for(i=0; i<r; i++)
    rt[i]=a[i+mid+1];
    int j=0, k=left;
    i=0;
    while(i<l && j<r)
    {
        if(lt[i]<rt[j]) a[k++]=lt[i++];
        else a[k++]=rt[j++];
    }
    while(i<l) a[k++]=lt[i++];
    while(j<r) a[k++]=rt[j++];
    return a;
}

void MergeSort(int *arr, int left, int right)
{
    if(left>=right) return;
    int mid=left + (right-left)/2;
    MergeSort(arr, left, mid);
    MergeSort(arr, mid+1, right);
    Merge(arr, left, mid, right);
}

int main()
{
    int n;
    cin>>n;
    int arr[n], i;
    for(i=0; i<n; i++)
    cin>>arr[i];
    MergeSort(arr, 0, n-1);
    cout<<"Sorted Array: ";
    for(i=0; i<n; i++)
    cout<<arr[i]<<" \n"[i==n-1];
    return 0;
}