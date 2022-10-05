// for binary_Search----> elements should be in monoatomic function(always in increasing or decresing order)
// complexity = O(log N)
#include <iostream>
using namespace std;   

int binarySearch(int arr[], int size, int key)
{
    int start = 0;
    int end = size - 1;
   // int mid = (start + end) / 2;  // mid=(s+e)/2 = s + (e-s)/2--->using this bcz when bigger value come they give error due to overflow range of int
                                  // = s + e/2 - s/2
                                  // = s/2 + e/2 = (s + e)/2
    
    int mid = start + (end - start)/2;
    while (start <= end)
    {
        if (arr[mid] == key)
        {
            return 1;
        }
        if (key > arr[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start)/2;
    }
    return 0;
}

int main()
{
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    cout << "Enter the element to search for: " << endl;
    int key;
    cin >> key;
  int found=binarySearch(arr,10,key);
  if(found){
      cout<<"Element is present"<<endl;
  }
  else{
      cout<<"Element is absent"<<endl;
  }
    return 0;
}