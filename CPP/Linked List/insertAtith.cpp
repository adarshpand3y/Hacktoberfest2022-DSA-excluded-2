#include "takeInput_print.h"

// Insert at ith position
node *insertNode(node *head, int i, int data)
{
    node *newNode = new node(data);
    int count = 0;
    node *temp = head;

    if (i == 0)
    {
        newNode->next = head;
        head = newNode;
        return head;
    }

    while (temp != NULL && count < i - 1)
    {
        temp = temp->next;
        count++;
    }
    if (temp != NULL)
    {
        newNode->next = temp->next;
        temp->next = newNode;
    }
    else {
        cout << "Out of bounds" << endl;
    }
    return head;
}

int main()
{
    node *head = takeInput(); // Refer to "takeInput.print.h" to see the working takeInput and print functions
    head = insertNode(head, 8, 10); // 0th-Index based
    print(head);
}