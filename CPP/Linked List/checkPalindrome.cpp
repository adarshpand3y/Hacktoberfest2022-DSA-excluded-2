#include<bits/stdc++.h>
using namespace std;

//structure defined for node
struct Node{
    public:
    int data;
    Node* next;
    Node(int x){
        data=x;
        next=NULL;
    }
};

//function to get middle and its previous
pair<Node*,Node*> findMidAndItsPrev(Node* head){
    
    Node* first=head;
    Node* second=head;
    Node* prev=NULL;
    while(second!=NULL && second->next!=NULL){
        prev=first;
        first=first->next;
        second=second->next->next;
    }
    Node* mid=first;
    pair<Node*,Node*> ans;
    ans.first=prev;
    ans.second=mid;
    return ans;
}

//function to reverse from middle
void reverseFromMid(pair<Node*,Node*> middle){
    Node* prev=NULL;
    Node* curr=middle.second;
    while(curr!=NULL){
        Node* next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    middle.first->next=prev;
}

//function to check palindrome
bool checkPalindrome(Node* head,int n){
    
    //pair is returned to get the Previous Node of the Middle Node 
    //that will help while reversing the linked list from middle 
    pair<Node*,Node*> middle=findMidAndItsPrev(head);
    if(n%2!=0){
        middle.first=middle.second;
        middle.second=middle.second->next;       
    }
    
    reverseFromMid(middle);
    
    Node* mid=middle.second;
    Node* start=head;
    
    while(mid!=NULL){
        if(mid->data!=start->data){
            //not a palindrome
            return false;
        }
        mid=mid->next;
        start=start->next;
    } 
    //is a palindrome
    return true;
}

int main(){
    //length of linked list
    int n;
    cin>>n;
    Node* prev=NULL;
    Node* head=NULL; 
    //input data and created liked list
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(prev==NULL){
            Node* newNode=new Node(x);
            head=newNode;
            prev=newNode;
        }
        else{
            Node* newNode=new Node(x);
            prev->next=newNode;
        }
    }
    
    //calling the function to check linked list to be a palindrome 
    if(checkPalindrome(head,n)){
        cout<<"It is a Palindrome"<<endl;
    }
    else{
        cout<<"It is not a Palindrome"<<endl;
    }

    return 0;
}