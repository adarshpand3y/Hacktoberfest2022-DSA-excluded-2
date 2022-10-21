#include<bits/stdc++.h>
using namespace std;
#define lli long long int

void factorize(int n){
    if(n == 1){
        cout<<"No prime factorization of 1!"<<endl;
        return;
    }
    for(int i = 2; i*i <= n; i++){
        if(n % i == 0){
            int count = 0;
            while(n % i == 0){
                count++, n /= i;
            }
            cout<<i<<"^"<<count<<" ";
        }
    }
    if(n > 1) cout<<n<<"^"<<1;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        factorize(n);
        cout<<"\n";
    }
    return 0;
}
