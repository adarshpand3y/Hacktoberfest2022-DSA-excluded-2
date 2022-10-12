#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>
void main()
{
clrscr();
int i,f;
char str[50];
cout<<"Enter the string ";
gets(str);
i=strlen(str);
for(int a=0,b=(i-1);a<=(i/2),b>=(i/2);++a,--b)
{
   if(str[a]!=str[b])
     {
     cout<<" It's not a palindrome ";
      break;
     }
   else { f=1; }
}
if(f==1) { cout<<" It's a palindrome ";    }

getch();
}
