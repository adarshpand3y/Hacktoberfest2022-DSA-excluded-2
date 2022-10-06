#include<iostream>
using namespace std;

class node {
    public:
    int data;
    node* next;

    //constructor
    node(int data){
        this-> data = data;
        this-> next = NULL;
    }

    //destructor
    ~node(){
        int value = this-> data;
        //memory free
        if(this-> next != NULL){
            delete next;
            this-> next = NULL;
        }
        cout<<"memory is free of data: "<<value<<endl;
    }
};
    
    //inserting a new node at head
    void insertAtHead(node* &head, int d){
        //create a new node
        node* temp = new node(d);
        temp-> next = head; 
        head = temp;
    }

    //printing the reverse linked list 
    void print(node* &head){
        //creating a temp node
        node* temp = head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp = temp-> next; //travelling from one node to another
        }
    }


int main() {
    int n;
    cout<<"Enter no. of nodes ";
    cin>>n;
    int d;
    cout<<"Enter the node 1 ";
    cin>>d;
    //creating a new node
    node* head = new node(d);
    for (int i = 0; i < (n-1); i++)
    {
        cout<<"Enter the node "<<i+2<<" ";
        cin>>d;
        insertAtHead(head, d);
    }
    cout<<"Linked List after reversing: "<<endl;
    print(head);   
return 0;
}