#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void printArr(int a[],int sz){
  printf("Array Elements:");
for(int i=0; i<sz; i++){
     printf("%d ",a[i]);
  }
  printf("\n");
}

void insertionSort(int *a[], int sz){
   int j,key;
   for(int i=1; i<sz; i++){
      int key=a[i];
      j=i-1;

      while(a[j]>key && j>=0){
         a[j+1]=a[j];
         j--;
      }
       a[j+1]=key;
   }
}

int main(){
int sz;
  printf("Enter the Size of Array\n");
  scanf("%d",&sz);
 int a[sz];
  printf("Enter the elements\n");
  for(int i=0; i<sz; i++){
     scanf("%d",&a[i]);
  }
 printArr(&a,sz);
 insertionSort(&a,sz);
 printf("Sorted ");
 printArr(a,sz);

    return 0;
}