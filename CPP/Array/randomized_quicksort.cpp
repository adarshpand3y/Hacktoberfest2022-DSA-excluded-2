#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int l, int h)
{
    int pivot = arr[l];
    int i=l;
    int j=h;
    while(i<j)
    {
        while(arr[i]<=pivot)
        {
            i++;
        }
        while(arr[j]>pivot)
        {
            j--;
        }
        if(i<j)
        {
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[j],arr[l]);
    return j;
}

int rand_partition(int arr[], int l, int h)
{
    int random = l+rand()%(h-l+1);
    swap(arr[l],arr[random]);
    return partition(arr,l,h);
}

void quicksort(int arr[], int l, int h)
{
    if(l<h)
    {
        int p = rand_partition(arr,l,h);
        quicksort(arr,l,p-1);
        quicksort(arr,p+1,h);
    }
}

int main()
{
    int arr[10] = {9,45,23,12,4,3,89,56,3,789};
    quicksort(arr,0,9);
    for(int i=0; i<10; i++)
    {
        cout<<arr[i]<<" ";
    }
}
