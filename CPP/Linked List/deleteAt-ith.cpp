#include "takeInput_print.h"

// Delete at ith position
node *deleteNode(node *head, int i)
{
    int count = 0;
    node *temp = head;
    if (i == 0)
    {
        node *a = head->next;
        delete head;
        return a;
    }
    while (temp != NULL && count < i - 1)
    {
        temp = temp->next;
        count++;
    }
    if (temp != NULL)
    {
        node *a = temp->next;
        temp->next = a->next;
        delete a;
    }
    return head;
}

int main()
{
    node *head = takeInput(); // // Refer to "takeInput.print.h" to see the working takeInput and print functions
    head = deleteNode(head, 0);
    print(head);
}