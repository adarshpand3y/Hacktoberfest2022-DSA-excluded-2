/*In This Code We can perform 6 operation on the matrix i.e Additon, Subtraction, Multiplication, Determinant, Trace and Transpose*/


#include <iostream>
using namespace std;

void get_matrix( int row,int column,int a[10][10] );
void matrix_addition(int row,int column,int a[10][10], int b[10][10] , int c[10][10]);
void matrix_subtraction(int row,int column,int a[10][10], int b[10][10], int c[10][10] );
void matrix_multiplication( int a[10][10], int b[10][10], int c[10][10],int row, int column);
void get_Cofactor(int a[10][10], int c[10][10], int p,int q, int n);
int  Determinant_of_matrix(int n, int a[10][10]);
void Trace_of_matrix(int row, int column, int a[10][10]);
void Transpose_of_matrix(int row, int column, int a[10][10], int c[10][10]);


int main()
{   
    int Firstmatrix[10][10];
    int secondmatrix[10][10];
    int resultantmatrix[10][10];
    
    cout<<"What do you want to perform?"<<endl;
    cout<<"1. If Determinant, Trace, Transpose."<<endl;
    cout<<"2. If Addition, Subtraction, Multiplication."<<endl;
    
    int i;
    cin>>i;
    if (i==1)
    {   
        i=0;
        int rowOfmatrix;
        int columnOfmatrix;
        cout<<"1.Determinant"<<"\n2.Trace"<<"\n3.Transpose"<<endl;
        cin>>i;
        cout<<"Enter number of Rows and columns:  ";
        cin>>rowOfmatrix>>columnOfmatrix;
        cout<<"Enter The Matrix"<<endl;
        get_matrix( rowOfmatrix ,columnOfmatrix , Firstmatrix ); 

        switch(i)
            {
            
            case 1:
                   {
                   cout<<"Determinant of matrix: "<<Determinant_of_matrix(rowOfmatrix ,Firstmatrix)<<endl;
                break;
                    }
            case 2:
                    {
                    Trace_of_matrix(rowOfmatrix, columnOfmatrix,Firstmatrix);
                    break;
                    }
                    
            case 3:
                    {
                    Transpose_of_matrix(rowOfmatrix, columnOfmatrix,Firstmatrix, resultantmatrix);
                    break;
                    }
            }
    }
    else if (i==2)
    {   i=0;
        int rowOfmatrix;
        int columnOfmatrix;
        cout<<"1.Addition"<<"\n2.Subtraction"<<"\n3.Multiplication"<<endl;
        cin>>i;
        cout<<"Enter number of Rows and columns:  ";
        cin>>rowOfmatrix>>columnOfmatrix;
        cout<<"Enter First Matrix"<<endl;
        get_matrix( rowOfmatrix ,columnOfmatrix , Firstmatrix );
        cout<<"Enter Second Matrix"<<endl;
        get_matrix( rowOfmatrix ,columnOfmatrix ,secondmatrix );
        switch(i)
            {
            case 1:
                   {
                    matrix_addition(rowOfmatrix,columnOfmatrix,Firstmatrix,secondmatrix, resultantmatrix );
                    break;
                   }
        
            case 2:
                   {
                    matrix_subtraction(rowOfmatrix,columnOfmatrix,Firstmatrix,secondmatrix, resultantmatrix );
                    break;
                   }
            case 3:
                   {
                    matrix_multiplication(Firstmatrix,secondmatrix,resultantmatrix,rowOfmatrix , columnOfmatrix);
                    break;
                   }
            }
    }
    
return 0;

}



void get_matrix( int row, int column, int a[10][10])
{
    for(int i=0; i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            cin>>a[i][j];
        }

    }
    cout<<endl;

}


void matrix_addition(int row,int column,int a[10][10], int b[10][10] ,int c[10][10] )
{ 
    for(int i=0; i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            c[i][j]=a[i][j]+b[i][j];
        }
    } 

    for(int i=0; i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            cout<<c[i][j]<<" ";
        }
         cout<<endl;
    } 
}
void matrix_subtraction(int row,int column,int a[10][10], int b[10][10] ,int c[10][10] )
{ 
    for(int i=0; i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            c[i][j]=a[i][j]-b[i][j];
        }
    } 

    for(int i=0; i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            cout<<c[i][j]<<" ";
        }
         cout<<endl;
    } 
}
void matrix_multiplication(int a[10][10], int b[10][10],int c[10][10],int row,int column )
{
    
    for (int  i = 0; i < row ; i++)
    {
        for(int j=0 ; j<column; j++)
        {
            c[i][j]= 0;
            for(int k=0; k< column; k++)
            {
                c[i][j] += a[i][k]*b[k][j];
            }
        }
    }
    
    for(int i=0; i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            cout<<c[i][j]<<" ";

        }
        cout<<endl;
    } 
}

void Trace_of_matrix(int row, int column, int a[10][10])
{
 int sum=0;
 for(int i=0;i<row;i++)
 {
    for(int j=0; j<column; j++)
    {
        if( i==j)
        {
            sum += a[i][j];
        }
    }
 }
    cout<<"Trace of the matrix : ";
    cout<<sum<<endl;
}


void get_Cofactor(int a[10][10], int c[10][10], int p,
                 int q, int n)
{
    int i = 0, j = 0;
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (row != p && col != q)
            {
                c[i][j++] = a[row][col];
                if (j == n - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
}
int Determinant_of_matrix(int n, int a[10][10])
{
    int D = 0;
    if (n == 1)
    {
        return(a[0][0]);
    }
    
        int c[10][10]; 
        int sign = 1; 
        for (int i = 0; i < n; i++)
        {
    
            get_Cofactor(a, c, 0, i, n);
            D += sign *a[0][i]* 
            Determinant_of_matrix(n - 1, c);
            sign = -sign;
        }
    return D;
}

void Transpose_of_matrix(int row, int column, int a[10][10], int c[10][10])
{
    for(int i=0; i<row; i++)
    {
        for(int j=0;j<column;j++)
        {
            c[j][i]= a[i][j];
        }
    }
    cout<<"Transpose of the matrix"<<endl;
    for(int i=0; i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            cout<<c[i][j]<<" ";

        }
        cout<<endl;
    } 
}



