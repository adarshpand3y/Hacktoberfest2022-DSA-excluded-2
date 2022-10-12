#include <bits/stdc++.h>
#include <vector>
using namespace std;
bool isSafe(vector<vector<int>> &v, int num, int x, int y)
{
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        if (v[x][i] == num)
        {
            return false;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (v[i][y] == num)
        {
            return false;
        }
    }
    int r = sqrt(n);
    int s = x - x % r;
    int t = y - y % r;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < r; j++)
        {
            if (v[i + s][j + t] == num)
            {
                return false;
            }
        }
    }
    return true;
}
bool Solve(vector<vector<int>> &v, int n, int x, int y)
{
    if (x == n - 1 && y == n)
    {
        return true;
    }
    if (y == n)
    {
        x++;
        y = 0;
    }
    if (v[x][y] > 0)
    {
        return Solve(v, n, x, y + 1);
    }
    for (int i = 1; i <= n; i++)
    {

        if (isSafe(v, i, x, y))
        {
            v[x][y] = i;
            if (Solve(v, n, x, y + 1))
            {
                return true;
            }
        }
        v[x][y] = 0;
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n;
    // cin >> n;
    n = 9;
    vector<vector<int>> vect{
        {0, 0, 0, 0, 0, 0, 0, 7, 0},
        {0, 0, 0, 0, 4, 7, 0, 0, 3},
        {0, 2, 0, 0, 9, 0, 0, 4, 0},
        {0, 0, 0, 5, 0, 0, 8, 0, 1},
        {0, 1, 0, 0, 0, 3, 0, 0, 0},
        {0, 0, 9, 2, 0, 0, 0, 0, 0},
        {3, 0, 0, 0, 0, 0, 6, 0, 0},
        {4, 9, 7, 0, 0, 0, 0, 0, 0},
        {2, 0, 0, 0, 0, 0, 3, 5, 0}};
    Solve(vect, n, 0, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << vect[i][j] << "  ";
        }
        cout << "\n";
    }
}