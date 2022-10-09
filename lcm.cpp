#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n1, n2;
    cin >> n1 >> n2;
    int start = max(n1, n2);
    int end = n1 * n2;
    int ans = 1;

    for (int i = start; i <= end; i++){
        if(i%n1 == 0 && i%n2 == 0){
            ans = i;
            break;
        }
    }
    cout << ans;

    return 0;
}
