#include "takeInput_print.h"

node *lastFirst(node *head)
{
    if(head -> next == NULL){
        return head;
    }

    node *tail = head;

    while (tail->next->next != NULL)
    {
        tail = tail->next;
    }

    node *temp = head;
    head = tail->next;
    tail->next = temp;
    head->next = temp -> next;
    temp -> next = NULL;

    return head;
}

int main(){
    node * head = takeInput(); // Refer to "takeInput.print.h" to see the working takeInput and print functions
    head = lastFirst(head);
    print(head);
}