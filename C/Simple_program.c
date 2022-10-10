#include<stdio.h>
void doWork(int a, int b, int*sum,int*prod,int*avg)
{
     *sum=a+b;
     *prod=a*b;
     *avg=(a+b)/2;
}
int main(){
    int a=3,b=5;
    int sum,prod,avg;
    doWork(a,b,&sum,&prod,&avg);
    printf("Sum=%d \nProduct= %d \nAverage=%d",sum,prod,avg);
    return 0;
}