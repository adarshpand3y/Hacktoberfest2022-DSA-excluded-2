/*
    Find middle element of linked list
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
Node* find_middle(Node* head)
{
    Node *slow = head, *fast = head;
    while(fast &&fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
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

    Node* ans = find_middle(head);
    cout<<"middle node is "<<ans->data<<"\n";
}
