#include <stdio.h>
#include <string.h>
int partition(int* a, int low, int high)
{
    int left = low;
    int pivotIdx = low + (high - low)/2;
    int pivot = a[pivotIdx];
    a[pivotIdx] = a[high];
    a[high] = pivot;
    pivotIdx = high;
    int partitionIdx = low;
    while (left < high)
    {
        if (a[left] < pivot) 
        {
            int tmp = a[left];
            a[left] = a[partitionIdx];
            a[partitionIdx] = tmp;
            ++partitionIdx;
        }
        ++left;
    }
    a[pivotIdx] = a[partitionIdx];
    a[partitionIdx] = pivot;
    return partitionIdx;
}
 
int quickselect(int* a, int low, int high, int k)
{
    if (low == high)
        return a[low];
    int pivotIdx = partition(a, low, high);
    int sizeOfLeftSubArray = pivotIdx - low + 1;
    if (sizeOfLeftSubArray > k)
    {
        return quickselect(a, low, pivotIdx-1, k);
    }
    else if (sizeOfLeftSubArray < k)
    {
        return quickselect(a, pivotIdx+1, high, k-sizeOfLeftSubArray);
    }
    else
    {
        return a[pivotIdx];
    }
}
int main()
{ printf("enter the number of elements in an array");
  int n;
  scanf("%d",&n);
  int arr[n];
  for(int i=0;i<n;i++)
  {
      scanf("%d",&arr[i]);
  }
  int k;
  printf("\nEnter the number 'k' to find the 'kth' largest element: ");
  scanf("%d", &k);
  printf("\nKth largest element is %d", quickselect(arr, 0,n-1, k));
  return 0;
}