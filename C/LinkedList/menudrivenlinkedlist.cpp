Program no.1:Menu driven program to perform the following operations:
1.creation of singly linked list
2.display the linked list.
3.insertion at beginning.
4.search the location of given element.
5.deletion of given node(loc is given).
6.deletion of given element(item is given).
7.exit	

#include<iostream>
using namespace std;
struct node
{
int info;
 struct node *link;
}*head,*newnode,*ptr;
void create()
{
    char ch='y';
    newnode=(struct node*)malloc(sizeof(struct node));
    cout<<"enter the number";
    cin>>newnode->info;
    newnode->link=NULL;
    head=newnode;
    ptr=newnode;
    while(ch=='y')
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        cout<<"enter the number";
        cin>>newnode->info;
        newnode->link=NULL;
        ptr->link=newnode;
        ptr=newnode;
        cout<<"want to continue";
        cin>>ch;
    }
}
void display()
{
    ptr=head;
    while(ptr!=NULL)
    {
        cout<<ptr->info;
        ptr=ptr->link;
    }
}
void insert()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    cout<<"enter any number";
    cin>>newnode->info;
    newnode->link=head;
    head=newnode;
}
void search()
{
    int item,loc=1;
   cout<<"enter the item";
   cin>>item;
   if(head==NULL)
   {
       cout<<"list not initiaized";
   }
   ptr=head;
   while(ptr!=NULL)
   {
       if(ptr->info==item)
       {
       cout<<"found at location:"<<loc;
       break;
       }
       loc++;
       ptr=ptr->link;
   }
}
void deletionnode()
{
    node*temp,*dd;
    int item,loc,c=1;
    ptr=head;
    cout<<"enter the location of element we want to delete";
    cin>>loc;
    while(ptr!=NULL)
    {
        c++;
        if(loc==c)
        {
            temp=ptr;
            ptr=ptr->link;
            break;
        }
        ptr=ptr->link;
    }
    temp->link=ptr->link;
    delete(ptr);
    cout<<"deleted node"<<loc;
}
void deletionele()
{
    int item;
    node*temp;
    ptr=head;
    cout<<"enter the element you want to delete";
    cin>>item;
    while(ptr->info!=item)
    {
        temp=ptr;
        ptr=ptr->link;
    }
    temp->link=ptr->link;
    delete (ptr);
    cout<<"node is deleted";
}

int main()
{
int ch;
while(ch!=7)
{
cout<<endl<<"1.creation of linked list";
cout<<endl<<"2.display the elements of linked list";
cout<<endl<<"3.insertion of given element at the beginning";
cout<<endl<<"4.search the location of given element in linked list";
cout<<endl<<"5.deletion of the given node ";
cout<<endl<<"6. deletion of given element";
cout<<endl<<"7. exit";
cout<<endl<<"enter your choice";
cin>>ch;
if(ch==1)
{
 create();
}
else if(ch==2)
{
 display();
}
else if(ch==3)
{
    insert();
}
else if(ch==4)
{
 search();
}
else if(ch==5)
{
    deletionnode();
}
else if(ch==6)
{
    deletionele();
}
}
}
