// Program to Print Hollow Rectangle

#include<iostream>
using namespace std;

int main()
{
    cout<<"Enter the number of rows and coloumns"<<endl; // The number of rows and columns must be greater than 2
    int row, col;
    cin>>row>>col;

    for(int i=1;i<=row;i++)
    {
        for(int j=1;j<=col;j++)
        {
            if(i==1 || i==row || j==1 ||  j==col)
            {
                cout<<"*";
            }
            else
            {
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}