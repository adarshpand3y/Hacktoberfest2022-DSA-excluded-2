#include <stdio.h>
#include <stdlib.h>

struct Node{
  int data;
  struct Node* next;
};
struct Node* head;


void Insert(int data){
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node*));
    temp->data=data;
    temp->next=head;
    head=temp;
    Print();
}

void DeleteEnd(){
    if(head==NULL){
        printf("No element to delete");
        return;
    }
    struct Node* temp=head;
    struct Node* temp1=head->next;
    while(temp1->next!=NULL){
        temp=temp->next;
        temp1=temp->next;
    }
    temp->next=temp1->next;
    printf("delete\n");
    Print();
    free(temp1);
}

void DeletePosi(int position){
    if(head==NULL){
        printf("No element to delete");
        return;
    }
    struct Node* temp1;
    temp1=head;
    for(int i=0;i<position-2;i++){
        temp1=temp1->next;
    }
    struct Node* temp=temp1;
    temp1=temp1->next;
    temp->next=temp1->next;
    Print();
    free(temp1);
}

void Print(){
    if(head==NULL){
        return;
    }
    struct Node *temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main()
{
    head=NULL;
    Insert(1);
    Insert(2);
    Insert(3);
    Insert(6);
    Insert(7);
    Insert(4);
    Insert(5);
    DeletePosi(3);
    DeletePosi(2);
    DeleteEnd();
    DeleteEnd();
    Print();
    return 0;
}