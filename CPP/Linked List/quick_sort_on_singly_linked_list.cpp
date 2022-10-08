/*

Quick sort on singly linked list

Time Complexity worst case- O(n^2) best/average case O(nlogn)
Space Complexity O(n)

Notes:
    1. find the last node and call quick_sort for head nad last node
    2. find the partition node
    3. recur from l to previous(p) and p->next tp h
    4. create a function to find the previous of p and also i
    5. before swaping or updating check if i is not null else point i to l

*/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insert(Node *&head, int val)
{
    Node *n = new Node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

void display(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << " NULL" << endl;
}

Node *lastNode(Node *head)
{
    while (head->next != NULL)
    {
        head = head->next;
    }
    return head;
}

Node *previous(Node *head, Node *p)
{
    if (p == NULL || p == head)
    {
        return NULL;
    }
    Node *temp = head;
    while (temp->next != p)
    {
        temp = temp->next;
    }
    return temp;
}

Node *partition(Node *&head, Node *l, Node *h)
{
    int x = h->data;
    Node *i = previous(head, l);

    for (Node *j = l; j != h; j = j->next)
    {
        if (j->data <= x)
        {
            if (i == NULL)
            {
                i = l;
            }
            else
            {
                i = i->next;
            }
            swap(i->data, j->data);
        }
    }
    if (i == NULL)
    {
        i = l;
    }
    else
    {
        i = i->next;
    }
    swap(i->data, h->data);
    return i;
}

void quickSort(Node *&head, Node *l, Node *h)
{
    if (h == NULL || h == l || l == h->next)
    {
        return;
    }
    Node *p = partition(head, l, h);
    Node *p_prev = previous(head, p);
    quickSort(head, l, p_prev);
    quickSort(head, p->next, h);
}

int main()
{
    Node *head = NULL;
    insert(head, 3);
    insert(head, 2);
    insert(head, 1);
    insert(head, 5);
    insert(head, 4);
    display(head);

    Node *l = head;
    Node *h = lastNode(head);
    quickSort(head, l, h);
    display(head);

    return 0;
}

/*

Output:

3 -> 2 -> 1 -> 5 -> 4 ->  NULL
1 -> 2 -> 3 -> 4 -> 5 ->  NULL

*/