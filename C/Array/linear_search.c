#include <stdio.h>

int search(int arr[], int n, int x) {
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

int main(void) {
int arr[500], n;
    printf("Enter the no of terms : ");
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        printf("Enter arr[%d] : ", i+1);
        scanf("%d", &arr[i]);
    }
    int x;
    printf("Enter no. to search : ");
    scanf("%d", &x);
    int result = search(arr, n, x);
    if(result == -1)
        printf("Element is not found");
    else
        printf("Element is present at index %d", result);
    return 0;
}
