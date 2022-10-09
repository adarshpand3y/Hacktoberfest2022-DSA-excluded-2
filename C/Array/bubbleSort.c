#include<stdio.h>
/*
max element at last 

Computation time :
 T(n) = (n-1)n/2 = theta(n^2)
*/

void swap(int* a, int*b ){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void printArr(int arr[],int n){
    for (int i = 0; i < n ; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void sort(int arr[],int n){
    for(int i = 0; i < n-1 ; i++)
    {
        for (int j = 0; j < n-1-i; j++){
                if(arr[j] > arr[j+1]){
                    swap(&arr[j],&arr[j+1]);
                }
        }
    printArr(arr,n);
    }
}


int main(){
    int arr[] = { 8, 5,9, 2, 3, 1,7};
    printf("bubble sort\n");
    sort(arr,7);
    return 0;
}