#include<stdio.h>
#include<stdlib.h>
#define MAX 5

 int s[MAX];
 int top=-1;
 void push(int item);
 int pop();
 void palindrome();
 void display();

 void main()
 {
     int choice,item;
     do
     {
         printf("\n----Menu-----\n");
         printf("1.Push\n");
         printf("2.pop\n");
         printf("3.palindrome\n");
         printf("4.display\n");
         printf("5.exit\n");
         printf("enter your choice: ");
         scanf("%d",&choice);
         switch(choice)
         {
             case 1: printf("enter element to be pushed ");
                     scanf("%d",&item);
                      push(item);
                      break;
             case 2:
                     pop();
                     break;
            case 3:palindrome();
                  break;
            case 4:display();
                  break;
            case 5:exit(0);

            default: printf("\n please enter valid choice ");
                break;
         }

     }while(choice!=5);
 }
 void push(int item)
 {
     if(top==MAX-1)
     {
         printf("stack overflow (MAX number of elements is 5");
         return;
     }
     top=top+1;
     s[top]=item;

 }
 int pop()
 {
     int item;
     if(top==-1)
     {
         printf("stack underflow");
         return -1;
     }
     item=s[top];
     printf("element popped is %d ",item);
     top=top-1;
 }
 void display()
 {
     int i;
     if(top==-1)
     {
         printf("stack is empty");
         return;
     }
     printf("stack elements are \n");
      for(i=top;i>=0;i--)
        printf("|%d|\n",s[i]);
 }
 void palindrome()
 {
     int flag=1,i;
     printf("stack contents are:\n");
     for(i=top;i>=0;i--)
        printf("|%d|\n",s[i]);
     printf("\nreverse of stack content are:\n");
     for(i=0;i<=top;i++)
        printf("|%d|\n",s[i]);
     for(i=0;i<=top/2;i++)
     {
         if(s[i]!=s[top-i])
         {
             flag=0;
             break;
         }
     }
     if(flag==1)
        printf("It is palindrome");
     else
        printf("It is not palindrome");
 }