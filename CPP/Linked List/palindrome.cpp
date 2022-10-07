#include "takeInput_print.h"

node *reverseRecursively(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node *rev = reverseRecursively(head->next);
    node *tail = head->next;
    tail->next = head;
    head->next = NULL;
    return rev;
}

// Check for palindrome
bool isPalindrome(node *head)
{
    if (head == NULL)
    {
        return true;
    }
    node *slow = head;
    node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    node *rev = reverseRecursively(slow->next);
    node *curr = head;
    while (rev != NULL)
    {
        if (rev->data == curr->data)
        {
            rev = rev->next;
            curr = curr->next;
        }
        else
        {
            return false;
        }
    }
    return true;
}

int main()
{
    node *head = takeInput();             // Refer to "takeInput.print.h" to see the working takeInput and print functions
    cout << isPalindrome(head) << endl; 
}