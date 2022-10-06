#include<iostream>
using namespace std;

int main(){
    cout<<"Enter the number of elements:"<<endl;
    int n;
    cin>>n;
    cout<<"Enter elements:";
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    int odd=0;
    int even=0;
    for(int i=0; i<n; i++){
        if(arr[i]%2==1){
            odd++;
        }
        else{
            even++;
        }
    }
    cout<<"Odd: "<<odd<<" "<<"Even: "<<even<<endl;
    return 0;
}