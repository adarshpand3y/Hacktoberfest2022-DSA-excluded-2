/*
NAME = HEMANT
ROLL = 2105372
SECTION = CSE-12
*/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *mid = NULL;
struct node *tail = NULL;
void list_print_karnewala();
void first_inser(int data);
struct node *first_delete()
{
    struct node *tempLink = head;
    head = head->next;
    return tempLink;
}
int length();

int searching_wala(int key) // changed to int
{
    struct node *mid = head;
    int count = 0; // to count each traverse
    if (head == NULL)
    {
        return 0;
    }
    while (mid->data != key) // whole list traverse karne wala
    {
        count++;
        if (mid->next == NULL)
        {
            return 0;
        }
        else
        {
            mid = mid->next; // next line jane wala
        }
    }
    count++;
    return count;
}

struct node *delete (int data)
{
    struct node *mid = head;
    struct node *previous = NULL;
    if (head == NULL)
    {
        return NULL;
    }
    while (mid->data != data)
    {
        if (mid->next == NULL) // if last hua to
        {
            return NULL;
        }
        else
        {
            previous = mid;
            mid = mid->next;
        }
    }
    if (mid == head)
    {
        head = head->next;
    }
    else
    {
        previous->next = mid->next;
    }
    return mid;
}

void sorting();
void middleNode();
int main()
{
    int i, n;
    int key;
    printf("\nenter the nodes u want to create \n");
    scanf("%d", &n);
    // changes made from here
    int arr[101] = {0};
    int k = 0;
    srand(time(0));
    while (k < n)
    {
        for (i = 0; i < n; i++)
        {
            int data = rand() % 100 + 1;
            if (arr[data] == 0)
            {
                first_inser(data);
                arr[data] = 1;
                break;
            }
        }
        k++;
    }
    // changes made till here
    printf("\nbefore sorting the linked list is \n");
    list_print_karnewala();
    printf("\n");
    printf("\n");
    sorting();
    printf("\nafter sorting your linked list is  \n");
    list_print_karnewala();
    printf("\n");
    printf("\n");
    middleNode();
    printf("\n");
    printf("\n");
    printf("\nenter key which u want to search \n");
    scanf("%d", &key);
    int count = searching_wala(key); // changed to int type
    if (count != 0)
    {
        printf("key is found at node number %d\n", count);
    }
    else
    {
        printf("not found sorry \n");
    }
    return 0;
}
void list_print_karnewala()
{
    struct node *ptr = head;
    printf(" %d ", ptr->data);
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
        printf(" %d ", ptr->data);
    }
}
void first_inser(int data)
{
    struct node *link = (struct node *)malloc(sizeof(struct node));
    struct node *flag = head;
    if (head == NULL)
    {
        head = link;
        link->data = data;
        link->next = NULL;
        printf("%d - is added in node\n", data);
    }
    else
    {
        while (flag->next != NULL)
        {
            flag = flag->next;
        }
        link->data = data;
        link->next = NULL;
        flag->next = link;
        printf("%d - is added in node\n", data);
    }
}
int length()
{
    int length = 0;
    struct node *mid;
    for (mid = head; mid != NULL; mid = mid->next)
    {
        length++;
    }
    return length;
}
void sorting()
{
    int i, j, k;
    int temp;
    struct node *mid;
    struct node *next;
    int size = length();
    k = size;
    for (i = 0; i < size - 1; i++, k--)
    {
        mid = head;
        next = head->next;
        for (j = 1; j < k; j++)
        {
            if (mid->data > next->data)
            {
                temp = mid->data;
                mid->data = next->data;
                next->data = temp;
            }
            mid = mid->next;
            next = next->next;
        }
    }
}
void middleNode()
{
    struct node *ptr = head;
    int count = 0;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }
    ptr = head;
    for (int i = 0; i < count / 2; i++)
    {
        ptr = ptr->next;
    }
    printf("\nmiddle of node hai: %d", ptr->data);
}
/*SOLVED BY :-
NAME = HEMANT
ROLL = 2105372
SECTION = CSE-12
*/