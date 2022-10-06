#include <stdio.h>
void merge(int a[], int l, int m, int u)
{
    int i, j, k;
    int r = m - l + 1;
    int s = u - m;
    int c[r], d[s];
    for (i = 0; i < r; i++)
        c[i] = a[l + i];
    for (j = 0; j < s; j++)
        d[j] = a[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < r && j < s) 
	{
        if (c[i] <= d[j]) 
		{
            a[k] = c[i];
            i++;
        }
        else {
            a[k] = d[j];
            j++;
        }
        k++;
    }
    while (i < r) {
        a[k] = c[i];
        i++;
        k++;
    }
    while (j < s) {
        a[k] = d[j];
        j++;
        k++;
    }
} 
void mergeSort(int a[], int l, int u)
{
    if (l < u) 
	{
        int m = l + (u - l) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, u);
        merge(a, l, m, u);
    }
}
int main()
{
    int a[50];
    int n, i;
    printf("Enter the no. of elements in the array ");
	scanf("%d", &n);
    for(i=0; i<n; i++)
	{
		printf("Enter %d element of array ", i+1);
		scanf("%d", &a[i]);
	}
	printf("\nUnsorted Array is ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
    mergeSort(a, 0, n - 1);
    printf("\nSorted Array is ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}
