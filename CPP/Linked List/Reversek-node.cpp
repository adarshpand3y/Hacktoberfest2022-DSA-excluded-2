#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int data)
    {
        this -> data =data;
        this -> next=NULL;
    }
};


void insertathead(node* &head, int val)
{
    node* temp=new node(val);
    temp->next=head;
    head=temp;
}


node* reversek(node* &head,int k)
{
    node*prev=NULL;
    node*curr=head;
    node* nextptr;
    int count=0;
    while(curr!=NULL && count<k)
    {
        nextptr=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextptr;
        count++;
    }
    if(nextptr!=NULL)
    {
        head->next=reversek(nextptr, k);
    }
    head=prev;
    return head;
}

void display(node* &head)
{
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}


int main()
{
    node* new1=new node(1);
    node* tail=new1;
    node* head=new1;

    insertathead(head,2);
    insertathead(head,3);
    insertathead(head,4);

    reversek(head,2);
    display(head);
}


