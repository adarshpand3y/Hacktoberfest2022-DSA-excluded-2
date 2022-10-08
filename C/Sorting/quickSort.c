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

int partition(int *a[],int low, int high){
   int i=low+1;
   int j=high;
   int pivot=a[low];
   int temp;
   do{
      while(a[i]<=pivot){
         i++;
      }
      while(a[j]>pivot){
         j--;
      }
   if(i<j){
      temp=a[i];
      a[i]=a[j];
      a[j]=temp;
   }
    }while(j>i);
   temp=a[j];
   a[j]=a[low];
   a[low]=temp;
   return j;
}

void quickSort(int *a[],int low,int high){
 if(low<high){
 int partitionindex=partition(a,low,high);
  quickSort(a,low,partitionindex-1);
  quickSort(a,partitionindex+1,high);
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
 printArr(a,sz);
 quickSort(&a,0,sz-1);
 printf("Sorted ");
 printArr(a,sz);

    return 0;
}