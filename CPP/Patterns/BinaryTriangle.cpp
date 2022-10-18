#include<iostream>
using namespace std;

int main()
{
    cout<<"Enter the number of rows"<<endl;
    int n;
    cin>>n;

    int i, j;

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=i;j++)
        {
            if((i-j)%2 == 0 || i==j)
            {
                cout<<" 1 ";
            }
            else
            {
                cout<<" 0 ";
            }
        }
        cout<<endl;
    }
    return 0;
}

// This pattern can also be printed by using the logic that (row+col)= even the print 1 & when (row+col)= odd print 0 :)