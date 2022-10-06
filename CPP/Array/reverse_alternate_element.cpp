#include <iostream>
using namespace std;
int main()
{
    int arr[4]={2,1,5,4};
    for (int i=0; i<=4; i+=2){
        if(i+1<4)
        {
            swap(arr[i],arr[i+1]);
        }
    }
    for(int i=0;i<4;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}