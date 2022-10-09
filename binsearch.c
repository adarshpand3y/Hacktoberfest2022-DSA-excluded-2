/*Program to search for an element in a sorted and rotated array using binary search*/
#include <stdio.h>
int middlepoint(int[],int,int);  //finds the point about which the array is rotated
int binsearch(int[],int,int,int); 
int pbinsearch(int arr[],int n,int key)  // If point is not found, then array is not rotated only
// If point found, then first compare with the key element and then search in two subarrays around that point
{
    int p=middlepoint(arr,0,n-1);
    if (p==-1)
        return binsearch(arr,0,n-1,key);
    if (arr[p]==key)
        return p;
    if (arr[0]<=key)
        return binsearch(arr,0,p-1,key);
    return binsearch(arr,p+1,n-1,key);
}
int middlepoint(int arr[],int low,int high)  // Function to get point. In our example, for array(4,5,1,2,3) it returns 4 (index of 3)
{
    if (high<low)
        return -1;
    if (high==low)
        return low;
    int mid=(low+high)/2;
    if (mid<high && arr[mid]>arr[mid+1])
        return mid;
    if (mid>low && arr[mid]<arr[mid-1])
        return (mid-1);
    if (arr[low]>=arr[mid])
        return middlepoint(arr,low,mid-1);
    return middlepoint(arr,mid+1,high);
}
int binsearch(int arr[],int low,int high,int key) //The known standard binary search technique is implemented here(using recursion).
{
    if (high<low)
        return -1;
    int mid=(low+high)/2; 
    if (key==arr[mid])
        return mid;
    if (key>arr[mid])
        return binsearch(arr,(mid+1),high,key);
    return binsearch(arr,low,(mid-1),key);
}
int main() //Main function to invoke function and print the index of the key element 3
{
    int arr1[] ={4,5,1,2,3};
    int n=sizeof(arr1)/sizeof(arr1[0]);
    int key=3;
    printf("Index of the element is : %d",pbinsearch(arr1,n,key));
    return 0;
}