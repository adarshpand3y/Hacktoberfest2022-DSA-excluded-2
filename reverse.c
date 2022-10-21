#include<stdio.h>
#include<math.h>

int main()
{
    int a,b,c;
    int d=0;
    
    printf("Enter the number to see it's reverse\n");
    scanf("%d",&b);
    c=b;
    
    while(b>0)
    {
        a=b%10;
        b=(b/10);
        d=d*10+a;
    }
    printf("REVERSE of the number is %d \n", d);
    return 0;
}