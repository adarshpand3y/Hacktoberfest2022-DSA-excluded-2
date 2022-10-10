#include <bits/stdc++.h>
#define int long long 
#define vi vector<int>
#define vi2d vector<int,int>
#define vs vector<string>
#define nl endl
using namespace std;
// Code for File handling:
//const string kanishkI = input.txt;
//const string kanishko = output.txt;
// ifstream fin(kanihskI);
//ofstream fout(knaishko);
 
 
 
 
signed main()
{
 ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int t;cin>>t;
while(t--){
 
 
    int n;
    cin>>n;
    if(n>3){

    
    for(int i =n-1;i>0;i--){
        cout<<i<<" ";
    }cout<<n<<nl;
    }
    else {
        for(int i =n;i>0;i--){
        cout<<i<<" ";
    }cout<<nl;
    }
    
    
}
return 0;
}