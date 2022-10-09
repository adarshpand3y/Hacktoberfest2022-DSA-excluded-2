/*
    reverse a linked list
*/

#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int value)
    {
        data  = value;
        next = NULL;
    }
};
void addnode(Node* &head, int value)
{
    Node* newNode = new Node(value);
    if(head == NULL)
    {
        head = newNode;
        return;
    }
    Node* tmp = head;
    while(tmp->next  != NULL)
        tmp = tmp->next;
    tmp->next = newNode;
    return;
}
Node* reverselist(Node* head)
{
    Node* prev = NULL;
    Node *current = head;
    Node* next_p ;

    while(current)
    {
        next_p = current->next;
        current->next = prev;

        prev = current;
        current = next_p;
    }
    head = prev;
    return head;
}
void printlist(Node* head)
{
    Node* tmp = head;
    while(tmp)
    {
        cout<<tmp->data<<" ";
        tmp = tmp->next;
    }
    cout<<endl;
    return;
}
int main()
{
    Node* head = NULL;
    addnode(head,1);
    addnode(head,2);
    addnode(head,3);
    addnode(head,4);
    addnode(head,5);
    addnode(head,6);
    addnode(head,7);

    cout<<"Linked list before reverse operation\n";
    printlist(head);
    head = reverselist(head);
    cout<<"Linked list after reverse operation\n";
    printlist(head);
    return 0;
}
