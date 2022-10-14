#include <iostream>
using namespace std;
int findMisNo (int arr[], int len){
   int temp;  
   temp  = ((len+1)*(len+2))/2;  
   for (int i = 0; i<len; i++)    
      temp -= arr[i];  
   return temp;
}
int main() {
   int n;   
   cout<<"Enter the size of array: "; 
   cin>>n;    int arr[n-1];  
   cout<<"Enter array elements: ";   
   for(int i=0; i<n; i++){    
      cin>>arr[i];  
   } 
   int misNo = findMisNo(arr,5); 
   cout<<"Missing Number is: "<<misNo;
   return 0;
}
