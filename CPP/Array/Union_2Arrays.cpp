#include<bits/stdc++.h>
using namespace std;
int main(){
    int m,n;
    cout<<"Enter the length of Arrays: ";
    cin>>m>>n;
    set<int>s;
    cout<<"Enter elements of 1st array: ";
    for(int i=0;i<m;i++){
        int str;
        cin>>str;
       s.insert(str);
    }
    cout<<endl;
    cout<<"Enter elements of 2nd array: ";
    for(int i=0;i<n;i++){
        int str;
        cin>>str;
       s.insert(str);
    }
    cout<<endl;
    cout<<"Union of 2 arrays is: ";
    for(auto value: s){
        cout<< value<<" ";
    }
}