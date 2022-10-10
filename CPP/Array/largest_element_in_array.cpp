#include<bits/stdc++.h>
using namespace std;
 
int sortArr(vector<int>& arr) {
    sort(arr.begin(),arr.end());
    return arr[arr.size()-1];
}

int largest_ele(vector<int>& arr){
    int largest = 0;
    for(int i=0; i<arr.size(); i++)
    {
        if(arr[i]>arr[largest])
        {
            largest = i;
        }
    }
    return arr[largest];
}
 
int main() {
    vector<int> arr1 = {2,5,1,3,0};
    vector<int> arr2 = {8,10,5,7,9};
   
    cout<<"The Largest element in the array is: "<<sortArr(arr1)<<endl;
    cout<<"The Largest element in the array is: "<<sortArr(arr2)<<endl;

    cout<<"The Largest element in the array without sorting the array is: "<<largest_ele(arr1)<<endl;
    cout<<"The Largest element in the array without sorting the array is: "<<largest_ele(arr2);
    return 0;
}