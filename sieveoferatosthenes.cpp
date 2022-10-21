#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define endl "\n"

bool is_not_prime[90000001];

void sieve(){
    is_not_prime[0] = is_not_prime[1] = 1;
    int maxN = 90000000;
    for(lli i = 2; i*i < maxN;i++){
        if(!is_not_prime[i]){
            for(lli j = i*i; j < maxN;j+=i){
                is_not_prime[j] = 1;
            }
        }
    }
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t;
    cin>>t;
    sieve();
    while(t--){
        int n;
        cin>>n;
        cout<<!is_not_prime[n]<<endl;
    }
    return 0;
}
