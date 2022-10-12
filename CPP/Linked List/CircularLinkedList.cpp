#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insertAtHead(node *&head, int val)
{
    node *temp = head;
    node *n = new node(val);

    if (head == NULL)
    {
        head = n;
        n->next = head;
        return;
    }
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
    head = n;
}

void insertAtTail(node *head, int val)
{
    node *temp = head;
    node *n = new node(val);
    if (head == NULL)
    {
        insertAtHead(head, val);
        return;
    }
    while (temp->next != head)
    {
        temp = temp->next;
    }

    temp->next = n;
    n->next = head;
}

void display(node *&head)
{
    node *temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
}

void deleteAtHead(node *&head)
{
    if (head == NULL)
    {
        return;
    }
    node *temp = head;
    node *toDelete = head;
    node *newHead = temp->next;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = newHead;
    head = newHead;
    delete toDelete;
}

void deletion(node *&head, int pos)
{
    node *temp = head;
    node *toDelete;
    int count = 1;
    if (pos < 1)
    {
        return;
    }
    else if (pos == 1)
    {
        deleteAtHead(head);
        return;
    }
    while (count != pos - 1)
    {
        temp = temp->next;
        count++;
    }
    toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}

int main()
{
    node *head = NULL;
    insertAtHead(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtHead(head, 1);
    deletion(head, 1);
    display(head);
    return 0;
}