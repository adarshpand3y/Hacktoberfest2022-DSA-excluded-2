// Program to print inverted triangle

#include<iostream>
using namespace std;

int main()
{
    cout<<"Enter the height(no of rows) of the triangle"<<endl;
    int row;
    cin>>row;
    int i, j;

    for(i=row;i>=1;i--)
    {
        for(j=1;j<=i;j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}