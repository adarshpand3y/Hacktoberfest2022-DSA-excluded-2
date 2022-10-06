#include<bits/stdc++.h>
using namespace std;

int main(){
    int n=4;
    int arr[n]={1, 3, 1, 2};
    map<int, int>mp;
    for(int i=0; i<n; i++){
        mp[arr[i]]++;
    }
    int ans=-1;
    for(auto it: mp){
        if(it.second>1)
            ans=it.first;
    }
    cout<<ans;
    return 0;
}