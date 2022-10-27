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

struct Node* ReverseRecur(struct Node* h){
    struct Node* next=NULL;
    struct Node* prev=NULL;
   if(h->next==NULL){
       
       head=h;
       return;
   }
   next=h->next;
   prev=h;
   h=next;
   ReverseRecur(h);
       if (h!=NULL){
   h->next=prev;
       }
       return prev;
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
    struct Node* t=ReverseRecur(head);
    t->next=NULL;
    Print();

    return 0;
}