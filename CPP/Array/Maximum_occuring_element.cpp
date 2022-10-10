#include<iostream>
#include<algorithm>
#include<map>
#include<iterator>
using namespace std;

int main(){
    int arr[]={ 40, 50, 30, 40, 50, 30, 30 };
    int n=7;
    map<int, int>mp;
    for(int i=0; i<n; i++){
        mp[arr[i]]++;
    }
    int ans=-1;
    int index=-1;
    for(auto it: mp){
        if(it.second>ans){
            index=it.second;
            ans=it.first;
        }
    }
    cout<<"Maximum Occuring Element :"<<ans;
    return 0;
}