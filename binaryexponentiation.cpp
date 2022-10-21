#include<bits/stdc++.h>
using namespace std;
#define lli long long int

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int a, n;
    cin>>a>>n;
    int res = 1;
    while(n){
        if(n % 2){
            res = res * a;
            n--;
        }
        a *= a, n /= 2;
    }
    cout<<res;
    return 0;
}
