#include<iostream>
using namespace std;

// creating node for linked list
class node{
public:
    int data;
    node *next;
    node(int val){
        data=val;
        next=NULL;
    }

};

//function for inserting elements
void insertAtTail(node* &head, int val){
    node* n= new node(val);
    if(head == NULL){
        head = n;
        return;
    }

    node* temp = head;
    while(temp->next != NULL){
        temp = temp -> next;
    }
    temp -> next = n;
    
}
// function todisplay linked list elements 
void display(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" -> ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;

}

//function to delete element at head
void deletionAtHead(node* &head){
    node* todelete = head;
    head = head->next;
    delete todelete;
}
//function to delete elements of LL
void deletion(node* &head, int val){
    if(head==NULL){
        return;
    }
    if(head->next == NULL){
        deletionAtHead(head);
    }
    node* temp = head;
    if(val==head->data){
        deletionAtHead(head);
    }
    else{

    while(temp->next->data != val){
        temp = temp->next;
    }
    node* todelete = temp->next;
    temp-> next = temp->next->next;
    delete todelete;
    }
}
int main(){
    node* head = NULL;

    //inserting LL elements
    insertAtTail(head,100);
    insertAtTail(head,200);
    insertAtTail(head,300);
    insertAtTail(head,400);
    insertAtTail(head,500);

    //displaying LL elements
    cout<<"Linked List Before Deletion :"<<endl;
    display(head);
    cout<<endl;

    //deleting element '400'
    deletion(head,400);
    deletion(head,200);
    
    //displaying LL elements
    cout<<"Linked List After Deletion of 400 and 200 :"<<endl;
    display(head);
    return 0;
}