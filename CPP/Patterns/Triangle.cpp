#include<iostream>
using namespace std;

int main()
{
    int row;
    cout<<"Enter the number of rows"<<endl;
    cin>>row;

    int i, j;

    for(i=1;i<=row;i++)
    {
        for(j=1;j<=row;j++)
        {
            if(j<=row-i)
            {
                cout<<" ";
            }
            else
            {
                cout<<"*";
            }
        }
        cout<<endl;
    }


    return 0;

}