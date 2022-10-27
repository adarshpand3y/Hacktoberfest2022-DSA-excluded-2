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
}

void DeleteFirst(){
    if(head==NULL){
        printf("empty list");
        return;
    }
    struct Node *temp=head;
    head=temp->next;
    temp->next->prev=NULL;
    free(temp);
    Print();
}

void DeleteLast(){
    struct Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    struct Node *temp1=temp->prev;
    temp1->next=NULL;
    temp->prev=NULL;
    free(temp);
    Print();
}

void DeletePosi(int position){
    struct Node* temp=head;
    if(position==1){
        temp->next->prev=NULL;
        head=temp->next;
        temp->next=NULL;
        Print();
        return;
    }
   
   
    for(int i=0;i<position-2;i++){
        temp=temp->next;
    }
    struct Node* temp1=temp->next;
   
    temp->next=temp1->next;
    temp->next->prev=temp;
   
    temp1->next=NULL;
    temp1->prev=NULL;
    free(temp1);
   
    Print();
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
    DeleteFirst();
    DeleteFirst();
    DeleteFirst();
    DeleteLast();
    DeleteLast();
    DeletePosi(5);
    DeletePosi(3);
    Print();

    return 0;
}