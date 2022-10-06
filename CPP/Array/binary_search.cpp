// mid is changed because it out integer range



#include <iostream>
using namespace std;
int binarySearch(int arr[], int size, int key)
{
    int start = 0;
    int end = size - 1;
    // int mid= (start+end)/2; on adding it will be out of range of integer
    int mid = start +(end-start)/2;
    while (start <= end)
    {
        if (arr[mid] == key)
        {
            return mid;
        }
        // go to right wala part
        if (key > arr[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start +(end-start)/2;
    }
    return -1;
}
int main()
{
    int even[6] = {2, 4, 6, 8, 12, 18};

    int evenIndex = binarySearch(even, 6, 4);

    cout << "index of 18-->" << evenIndex << endl;
    return 0;
}
