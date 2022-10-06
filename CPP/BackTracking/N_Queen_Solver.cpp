#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool issafe(vector<vector<int>> board, int row, int col)
{
    // checking the currenrt row already has element or not
    for (int i = 0; i < col; i++)
    {
        if (board[row][i])
        {
            return false;
        }
    }
    // Checking Upper Left diagonal
    int row1 = row - 1, col1 = col - 1;
    while (row1 >= 0 and col1 >= 0)
    {
        if (board[row1--][col1--])
        {
            return false;
        }
    }

    // Checking Bottom diagonal
    row1 = row + 1, col1 = col - 1;
    while (row < board.size() and col >= 0)
    {
        if (board[row++][col--])
        {
            return false;
        }
    }
    return true;
}

void printNqueen(vector<vector<int>> &board, int col, int &count, int n)
{
    if (col == n)
    {
        count++;
        return;
    }
    // We will try to place for every col in rows 0,1,2
    for (int i = 0; i < n; i++)
    {
        if (issafe(board, i, col))
        {
            board[i][col] = 1;
          // In case to just now True or false - change return type to bool ans this line to
          //if(printNqueen(board, col + 1, count, n)) return true;
            printNqueen(board, col + 1, count, n);
            board[i][col] = 0;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int count = 0;
    vector<vector<int>> board(n, vector<int>(n, 0));
    printNqueen(board, 0, count, n);
    cout << count << endl;

    return 0;
}