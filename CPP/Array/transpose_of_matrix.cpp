//Transpose of a matrix

#include<iostream>
using namespace std;
int main()
{
        int arr1[3][3], i, j, arr2[3][3];
        cout<<"\n Enter 3*3 Array Elements : \n";
        for(i=0; i<3; i++)
        {
                for(j=0; j<3; j++)
                {
                        cout<<" ";
                        cin>>arr1[i][j];
                }
        }
        cout<<"\n Array Elements : \n";
        for(i=0; i<3; i++)
        {
                for(j=0; j<3; j++)
                {
                        cout<<" ";
                        cout<<arr1[i][j]<<"\t";
                }
                cout<<"\n";
        }
        for(i=0; i<3; i++)
        {
                for(j=0; j<3; j++)
                {
                        cout<<" ";
                        arr2[i][j]=arr1[j][i];
                }
        }
        cout<<"\n\n Transpose of the Matrix is :\n";
        for(i=0; i<3; i++)
        {
                for(j=0; j<3; j++)
                {
                        cout<<" ";
                        cout<<arr2[i][j]<<"\t";
                }
                cout<<"\n";
        }
        return 0;
}