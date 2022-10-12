#include <bits/stdc++.h>
using namespace std;
int SCS(string a, string b, int l, int m)
{
    if (a.size() == 0)
    {
        return b.size();
    }
    if (b.size() == 0)
    {
        return a.size();
    }
    if (a[0] == b[0])
    {
        return 1 + SCS(a.substr(1, l - 1), b.substr(1, m - 1), l - 1, m - 1);
    }
    else
    {
        return min(1 + SCS(a.substr(1, l - 1), b, l - 1, m), 1 + SCS(a, b.substr(1, m - 1), l, m - 1));
    }
}
int SCSDP(string a, string b, int l, int m)
{
    int arr[l + 1][m + 1];
    for (int i = 0; i <= l; i++)
    {
        arr[i][0] = i;
    }
    for (int i = 0; i <= m; i++)
    {
        arr[0][i] = i;
    }
    for (int i = 1; i <= l; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                arr[i][j] = 1 + arr[i - 1][j - 1];
            }
            else
            {
                arr[i][j] = min(1 + arr[i - 1][j], 1 + arr[i][j - 1]);
            }
        }
    }
    return arr[l][m];
}
int main()
{
    string a, b;
    // cin >> a;
    // cin >> b;
    a = "aggtab";
    b = "axtxayb";
    int l, m;
    l = a.length();
    m = b.length();
    cout << SCS(a, b, l, m);
    reverse(s.begin(), s.end());
    // OR WE CAN ALSO USE size of a+size of b -LCS(a,b,l,m);
}