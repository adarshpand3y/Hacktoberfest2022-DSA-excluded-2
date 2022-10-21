#include<bits/stdc++.h>
using namespace std;
#define lli long long int

bool isPrime(lli n){
    if(n <= 1) return 0;
    for(int i = 2; i*i <= n; i++){
        if(n%i==0) return 0;
    }
    return 1;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t;
    cin>>t;
    while(t--){
        lli n;
        cin>>n;
        cout<<isPrime(n)<<endl;
    }
    return 0;
}
