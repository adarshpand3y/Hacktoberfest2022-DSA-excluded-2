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

void InsertEnd(int value){
    struct Node *temp=(struct Node*)malloc(sizeof(struct Node*));
    temp->data=value;
    temp->next=NULL;
    struct Node *temp2=head;
    if(head==NULL){
        head=temp;
        temp->prev=NULL;
        return;
    }
   
    while(temp2->next!=NULL){
        temp2=temp2->next;
    }
    temp2->next=temp;
    temp->prev=temp2;
    Print();
}

void InsertPosi(int position,int value){
    struct Node *temp=(struct Node*)malloc(sizeof(struct Node*));
    struct Node *temp1=head;
    temp->data=value;
   
    if(head==NULL){
        printf("empty list");
        return;
    }
   
    if(position==1){
        temp->next=head;
        temp->prev=NULL;
        head->prev=temp;
        head=temp;
        Print();
        return;
    }
   
   
    for(int i=0;i<position-2;i++){
        temp1=temp1->next;
    }
    temp->next=temp1->next;
    temp->prev=temp1;
    temp1->next=temp;
    temp->next->prev=temp;
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
    InsertEnd(4);
    InsertEnd(5);
    InsertEnd(6);
    InsertPosi(2,7);
    InsertPosi(5,8);
    InsertPosi(1,9);
    Print();

    return 0;
}