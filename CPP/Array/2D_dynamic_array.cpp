#include <iostream>
using namespace std;

int main()
{
    cout << endl;

    int n, m;
    cin >> n >> m;

    // creating a 2D array
    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[m];
    }

    // taking input
    for (int k = 0; k < n; k++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[k][j];
        }
    }

    // printing the array
    cout << endl;
    for (int k = 0; k < n; k++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[k][j] << " ";
        }
        cout << endl;
    }

    // releasing memory
    for (int i = 0; i < n; i++)
    {
        delete[] arr[i];
    }

    delete[] arr;

    cout << endl;

    return 0;
}