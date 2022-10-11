#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void insertAtBeginning(struct Node *head, int Data) // Insertion of Node At Beginning
{
    Node *newNode = new Node();
    newNode->data = Data;
    newNode->next = head;
    head = newNode;
};

struct Node*  insertAtEnd(struct Node *head, int Data) // Insertion of Node At the End
{
    struct Node *temp = head;
    Node *newNode = new Node();
    newNode->data = Data;
    newNode->next = NULL;
    if (head == NULL)
    {
        newNode->next = NULL;
        return newNode;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    return head;
}

void PrintList(struct Node *head) // Function to Print the LinkList
{
    Node *temp = head;
    while (temp->next != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << temp->data << "\n";
};

struct Node *reverseLinkedList(struct Node *head) // Function to reverse a linklist
{
    struct Node *dummy = NULL;
    while (head != NULL)
    {
        struct Node *nxt = head->next;
        head->next = dummy;
        dummy = head;
        head = nxt;
    }
    return dummy;
}

int main()
{
    Node *head = NULL;
    int numberOfNodes;
    cin >> numberOfNodes;
    for (int i = 0; i < numberOfNodes; i++)
    {
        int Data;
        cin >> Data;
        head = insertAtEnd(head, Data);
    }
    PrintList(head);
    head = reverseLinkedList(head);
    PrintList(head);
    return 0;
}
