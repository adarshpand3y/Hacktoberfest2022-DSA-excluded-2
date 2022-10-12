/******************************************************************************

Selection Sort
*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
    int n,a[n],c=0;
    
    cout<<"Enter Size of List :";
    cin>>n;
    
    for(int i=0;i<n;i++){
    cout<<"Enter "<<i<<" element : ";cin>>a[i];
    }
    
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[j]<a[i]){
                int temp = a[j];
                a[j] = a[i];
                a[i] = temp ;
                c+=1;
            
            }
        }
    }
    
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    cout<<"Swap require :"<<c;
    

    return 0;
}
