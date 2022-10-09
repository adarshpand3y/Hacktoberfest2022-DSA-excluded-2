#include<stdio.h>
#include<stdlib.h>

void merge(int arr[], int l, int m, int r){
    int n1 = m-l+1;
    int n2 = r-m;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[l+i];
    for (int i = 0; i < n2; i++) R[i] = arr[m+1+i];
    
    int i =0,j=0,k=l;

    while(i<n1 && j<n2){
        if (L[i]<=R[j])
        {
            arr[k] = L[i];
            i++;
        }else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k] = R[j];
        j++;
        k++;
    }     
}

void mergeSort(int arr[], int l, int r){
    if(l<r){
        int m = l+ (r-l)/2;

        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

void printer(int arr[], int len){
    printf("\n");
    for (int i = 0; i < len; i++)
    {
        printf("%d\t",arr[i]);
    }
        printf("\n");  
}

int main(){
    int len;
    printf("Enter length of array\n ");
    scanf("%d",&len);
    int arr[len];
    for (int i = 0; i < len; i++)
    {
        arr[i] = rand()%100 +1;
    }
    printer(arr,len);
    mergeSort(arr,0,len-1);
    printer(arr,len);
    
}