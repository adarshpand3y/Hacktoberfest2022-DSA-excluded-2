// Linked-List : Inserting Node at Head

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* head=NULL;

void InsertNode(int x){
    Node* temp=new Node();
    temp->data=x;
    temp->next=head;
    head=temp;
};

void PrintList(){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"\n";
        temp=temp->next;
    }
};

int main(){
    int n,x;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>x;
        InsertNode(x);
    }    
    PrintList();
}
}

