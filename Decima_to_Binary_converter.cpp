#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a, b=0;
    int n;
    cout<<"Enter a number in Decimal Number System"<<endl;
    cin>>n;

    while(n>0)
    {
        a= n%2;
        b= (b*10)+a;
        n= n/2;
    }
   int p, q=0;
   while(b>0)
   {
       p= b%10;
       q= (q*10)+p;
       b=b/10;
   }
    cout<<"The Binary equivalent is: "<< q;
    
    return 0;
}