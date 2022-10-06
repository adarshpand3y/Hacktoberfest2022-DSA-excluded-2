//Insertion Sort Algorithm


#include <bits/stdc++.h>
using namespace std;
void insertionSort(int a[], int n)
{
	int i, o, j;
	for (i = 1; i < n; i++)
	{
		o = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > o)
		{
			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j + 1] = o;
	}
}
void printArray(int a[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}

int main()
{
	int arr[] = { 5,23,10,2,56,4 };
	int n = sizeof(arr) / sizeof(arr[0]);
	insertionSort(arr, n);
	printArray(arr, n);
	return 0;
}

