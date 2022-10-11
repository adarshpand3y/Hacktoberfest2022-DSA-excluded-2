#include<stdio.h>
/*
insert smaller element in between
Time complexity : n(n-1)/2 = theta(n^2)
*/

void printArr(int arr[],int n){
    for (int i = 0; i < n ; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void insertionSort( int arr[], int n){
    for(int i = 0; i < n; i++){
        int key = arr[i];
        int j = i;
        while(j> 0 && arr[j-1]> key){
            arr[j] = arr[j-1];
            j = j-1;
        }
        arr[j] = key;
        printArr(arr,n);
    }
}

int main(){
    int arr[] = {8,5,9,2,3,1,7};
    printf("insertion sort\n");
    insertionSort(arr,7);
    return 0;
}


