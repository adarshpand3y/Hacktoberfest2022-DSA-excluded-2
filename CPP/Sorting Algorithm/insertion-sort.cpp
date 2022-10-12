/******************************************************************************

insertion sort

*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
    
    int n=5;
    int a[n]={87,13,76,8,23};
    
    for(int i=1;i<n;i++){
        int c = a[i];
        int j = i-1;
        while(a[j]>c && j>=0){
            a[j+1]=a[j];
            j--;
        }
        
        a[j+1]=c;
    }

    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }cout<<endl;
        
}
