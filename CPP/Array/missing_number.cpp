#include<bits/stdc++.h>
using namespace std;

int main(){
    int n=5;
    int arr[n-1]={1,2,4,5};
    int sum=0;
    for(int i=0; i<n-1; i++){
        sum+=arr[i];
    }
    int sum2=(n*(n+1))/2;
    cout<<sum2-sum;
    return 0;
}