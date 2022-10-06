//I have changed this program

#include <stdio.h>

int search(int arr[], int n, int x) {
    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == x)
            return i+1;
    }
    return -1;
}

int main() {
int arr[]={70, 40, 30, 11, 57, 41, 25, 14, 52};
    // printf("Enter the no of integers : ");
    // scanf("%d", &n);
    // for(int i=0; i<n; i++){
    //     printf("Enter arr[%d] : ", i+1);
    //     scanf("%d", &arr[i]);
    // }
    int x=  41;
     int n = sizeof(arr) / sizeof(arr[0]); // size of array  
  int res = search(arr, n, x); // Store result  
  printf("The elements of the array are - ");  
  for (int i = 0; i < n; i++)  
  printf("%d ", arr[i]);   
  printf("\nElement to be searched is - %d", x);  
  if (res == -1)  
  printf("\nElement is not present in the array");  
  else  
  printf("\nElement is present at %d position of array", res);  
  return 0;  
}  