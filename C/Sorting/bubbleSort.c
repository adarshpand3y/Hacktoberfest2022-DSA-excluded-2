#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void printArr(int a[],int sz){
for(int i=0; i<sz; i++){
     printf("%d ",a[i]);
  }
  printf("\n");
}

void bubbleSort(int *a[],int sz){
   int temp;
   int isSorted=0;
    for(int i=0; i<sz; i++){
       isSorted=1;
   printf("Working on Pass %d\n",i+1);
     for(int j=i+1; j<sz; j++){
        if(a[i]>a[j]){
            temp=a[j];
            a[j]=a[i];
            a[i]=temp;
            isSorted=0;
        }
     } if(isSorted) return ;
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
bubbleSort(&a,sz);
printf("Sorted Elements:");
  printArr(a,sz);
  

    return 0;
}