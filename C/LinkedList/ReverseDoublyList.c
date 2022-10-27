#include <stdio.h>
#include<stdlib.h>

struct Node{
    struct Node* prev;
    int data;
    struct Node* next;
};

struct Node* head;

void InsertFirst(int value){
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node*));
    temp->data=value;
    temp->prev=NULL;
    if(head==NULL){
        head=temp;
        temp->next=NULL;
        return;
    }
    temp->next=head;
    head->prev=temp;
    head=temp;
    Print();
}

void ReverseRecur(struct Node* h){
    static struct Node* temp;
    static struct Node* p;
    static struct Node* n;
   
    temp=h;
   
    if(temp==NULL){
        head=p->prev;
        Print();
        return;
    }
   
        p=temp->prev;
        n=temp->next;
        temp->next=p;
        temp->prev=n;
        temp=n;
       
        ReverseRecur(temp);
}


void Print(){
    struct Node* temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main()
{
    head=NULL;
    InsertFirst(1);
    InsertFirst(2);
    InsertFirst(3);
    InsertFirst(4);
    InsertFirst(5);
    ReverseRecur(head);
    Print();

    return 0;
}