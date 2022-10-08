#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void printArr(int a[],int sz){
for(int i=0; i<sz; i++){
     printf("%d ",a[i]);
  }
  printf("\n");
}

void selectionSort(int *a[], int sz){
  int temp,key;
  for(int i=0; i<sz-1; i++){
    key=i;
     for(int j=i+1; j<sz; j++){
       if(a[key]>a[j]){
         key=j;
      
       }
     }
     temp=a[key];
     a[key]=a[i];
     a[i]=temp; 
  }
}

int main(){
  // 4 3 5 1
int sz;
  printf("Enter the Size of Array\n");
  scanf("%d",&sz);
int a[sz];
  printf("Enter the elements\n");
  for(int i=0; i<sz; i++){
     scanf("%d",&a[i]);
  }
  printf("Elements: ");
  printArr(a,sz);
  selectionSort(&a,sz);
  printf("\nSorted Elements:");
  printArr(a,sz);

    return 0;
}
