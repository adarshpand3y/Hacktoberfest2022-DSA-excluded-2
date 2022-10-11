#include <stdio.h>
#include <stdlib.h>

void selectionSort(int arr[], int size){

    for (int i = 0; i < size - 1; i++){

        /*Find the smallest element*/
        int smallest = i;
    
        for(int k = i + 1; k < size ; k++){
            if (arr[smallest] > arr[k])
            smallest = k;
        }
        if ( i != smallest ){
            int temp = arr [i];
            arr[i] = arr[smallest];
            arr[smallest] = temp;
        }
    }
}

void printArray(int a[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

int main()
{
	int array[] = { 6, 7, 3, 4, 1 };
	int array_size = sizeof(array) / sizeof(array[0]);

	printf("Given array is \n");
	printArray(array, array_size);

	selectionSort(array, array_size);

	printf("\nSorted array is \n");
	printArray(array, array_size);
	return 0;
}