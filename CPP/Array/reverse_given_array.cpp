#include <iostream>
using namespace std;
//Function to print array
void printArray(int ans[], int n) {
  cout << "The reversed array is:- " << endl;
   for (int i = 0; i < n; i++) {
      cout << ans[i] << " ";
   }
}
//Function to reverse array using an auxiliary array
//No need for extra array
void reverseArray(int arr[], int n) {
   int l=0, r=n-1;  //two variable storing the address of first and last element in array
   while(l<=r){
      int temp=arr[l];
      arr[l]=arr[r];
      arr[r]=temp;
      l++;
      r--;
   }
   printArray(arr, n);
}
int main() {
   int n = 5;
   int arr[] = {5,4,3,2,1};
   reverseArray(arr, n);
   return 0;
}