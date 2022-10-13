// This program performs the following operations on Linked List- Insertion,deletion, reversal,searching in a linked list by taking user input
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void printList(struct Node *n)
{
    printf("Linked List: ");
    while (n != NULL)
    {
        printf("%d ", n->data);
        n = n->next;
    }
    printf("\n");
}
void search(struct Node *n, int ele)
{
    int f = 0;
    while (n != NULL)
    {
        if (n->data == ele)
        {
            f = 1;
            break;
        }
        n = n->next;
    }
    if (f == 1)
    {
        printf("%d found.", ele);
    }
    else
    {
        printf("%d not found.", ele);
    }
}
void inputList(struct Node *start, int n)
{
    // node 1
    int item;
    struct Node *temp;
    printf("Enter data for node 1: ");
    scanf("%d", &item);
    start->data = item;
    temp = start;
    // other nodes
    for (int i = 2; i <= n; i++)
    {
        struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter data for node %d: ", i);
        scanf("%d", &item);
        new_node->data = item;
        temp->next = new_node;
        temp = temp->next;
    }
    temp->next = NULL;
    printList(start);
}
struct Node *insert(struct Node *p, int loc, int item)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = item;
    struct Node *t = p;
    if (loc == 0)
    {
        new_node->next = p;
        p = new_node;
        t = new_node;
    }
    else
    {
        for (int i = 0; i < loc - 1; i++)
        {
            p = p->next;
        }
        new_node->next = p->next;
        p->next = new_node;
    }
    return t;
}
void revList(struct Node *start, int n)
{
    printf("Reversed Linked List: ");
    struct Node *temp;
    for (int i = n; i >= 0; i--)
    {
        temp = start;
        for (int j = 0; j < i; j++)
        {
            temp = temp->next;
        }
        printf("%d ", temp->data);
    }
    printf("\n");
}
struct Node *deleteNode(struct Node *head, int n, int position)
{
    struct Node *temp;
    struct Node *prev;
    temp = head;
    prev = head;
    for (int i = 0; i < position; i++)
    {
        if (i == 0 && position == 1)
        {
            head = head->next;
            free(temp);
        }
        else
        {
            if (i == position - 1 && temp)
            {
                prev->next = temp->next;
                free(temp);
            }
            else
            {
                prev = temp;

                // Position was greater than
                // number of nodes in the list
                if (prev == NULL)
                    break;
                temp = temp->next;
            }
        }
    }
    return head;
}
void print_address(struct Node *start, int n)
{
    for (int i = 0; i < n; i++)
    {
        while (start->next != NULL)
        {
            start = start->next;
        }
    }
    printf("%ld\n", start);
}

int main(void)
{
    int no, ele, loc;
    struct Node *start = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter no. of nodes: ");
    scanf("%d", &no);
    inputList(start, no);
    printf("Enter element to search: ");
    scanf("%d", &ele);
    search(start, ele);
    printf("\nEnter ele and index to insert: ");
    scanf("%d %d", &ele, &loc);
    start = insert(start, loc, ele);
    printList(start);
    revList(start, no);
    printList(start);
    printf("Enter position to delete: ");
    scanf("%d", &ele);
    start = deleteNode(start, no, ele);
    printList(start);
    print_address(start, no);
}

// Insertion in Linked List
/*
#include <stdio.h>
#include <stdlib.h>
struct Node // globally defined
{
    int data;
    struct Node *next;
};
// print Linked List
void printList(struct Node *n)
{
    while (n != NULL)
    {
        printf("%d ", n->data);
        n = n->next;
    }
    printf("\n");
}

// insertion at beginning
void push_beg(struct Node *head, int item)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = item;
    new_node->next = head;
    head = new_node;
}
// insertion at any loc
void insert_after(struct Node *prev_node, int item)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->data = item;
    n->next = prev_node->next;
    prev_node->next = n;
}

int main(void)
{
    struct Node *head = NULL;
    struct Node *second = NULL;
    struct Node *third = NULL;
    // allocate 3 nodes in the heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    head->data = 1;      // assign data in first node
    head->next = second; // link first node with second
    second->data = 2;
    second->next = third;
    third->data = 3;
    third->next = NULL;
    printf("Linked list: ");
    printList(head);

    int c;
    printf("Enter element to insert after third node: ");
    scanf("%d", &c);
    insert_after(third, c);
    printList(head);

    int item;
    printf("Enter element to insert at beginning: ");
    scanf("%d", &item);
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = item;
    new_node->next = head;
    head = new_node;
    printList(head);
}
*/