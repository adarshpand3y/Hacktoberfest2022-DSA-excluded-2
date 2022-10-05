//Insertion Sort Algorithm

#include<bits/stdc++.h>
using namespace std;

void insertionsort(int a[], int n){
    for(int i=1; i<n; i++){
        int value=a[i];
        int blank=i;
        while(blank>0 && (a[blank-1]>value)){
            a[blank]=a[blank-1];
            blank--;
        }
        a[blank]=value;
    }
    for(int i=0; i<n; i++)
    cout<<a[i]<<" ";
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
    cin>>a[i];
    insertionsort(a,n); 
}
