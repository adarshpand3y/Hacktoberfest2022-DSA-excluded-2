#include <iostream>
using namespace std;

bool binarySearch(int *arr, int k, int s, int e)
{
    if (s > e)
        return 0;

    int mid = s + (e - s) / 2;

    if (arr[mid] == k)
        return 1;
    else if (arr[mid] > k)
        return binarySearch(arr, k, s, mid - 1);
    else
        return binarySearch(arr, k, mid + 1, e);
}

int main()
{
    cout << endl;

    int arr[8] = {1, 2, 5, 7, 8, 9, 13, 18};
    int key = 3;

    if (binarySearch(arr, key, 0, 7))
        cout << "Key is present" << endl;
    else
        cout << "Key is not present" << endl;
    cout << endl;

    return 0;
}