#include <bits/stdc++.h>

using namespace std;
//Function to print array
void printArray(int ans[], int n) {
  cout << "The reversed array is:- " << endl;
   for (int i = 0; i < n; i++) {
      cout << ans[i] << " ";
   }
}
//Function to reverse array by swapping elements
//two pointer method to swap elements 
void reverseArray(int arr[], int n) {
  int i=0;
  int j=n-1;
   while(i<j){
     swap(arr[i++],arr[j--]);
   }
   printArray(arr, n);
}
int main() {
   int n = 5;
   int arr[10000];
  for(int i=0;i<n;i++){
cin>>arr[i];
  }
   reverseArray(arr, n);
   return 0;
}
