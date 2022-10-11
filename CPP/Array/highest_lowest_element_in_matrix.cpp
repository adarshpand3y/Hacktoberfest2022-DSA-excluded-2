#include<iostream>
using namespace std;
 
int main()
{
    int a,b,i,j,highest,lowest;
	int array[10][10];

    cout<<"Enter number of rows and columns= ";
    cin>>a>>b;
    
    cout<<endl<<"Enter Matrix Elements= "<<endl;
    
    for(i=0;i<a;++i)
    {
        for(j=0;j<b;++j)
        cin>>array[i][j];
    }
 
    highest=array[0][0];
    lowest=array[0][0];
    
    for(i=0;i<a;++i)
    {
        for(j=0;j<b;++j)
        {
            if(array[i][j]>highest)
                highest=array[i][j];
            else
                if(array[i][j]<lowest)
                    lowest=array[i][j];
        }
    }
    
    cout<<endl<<"Highest Element="<<highest<<endl<<"Lowest Element="<<lowest<<endl;
 
    return 0;
}