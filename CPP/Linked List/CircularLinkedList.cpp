
#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int a)
    {
        data = a;
        next = NULL;
    }
};

void circulardisplay(node *head)
{
    node *temp = head->next;
    cout << head->data << " ";

    while (temp != head)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << temp->data << " ";
}
int count(node *head)
{
    node *temp = head->next;
    int i = 1;

    while (temp != head)
    {
        i++;
        temp = temp->next;
    }
    return i;
}

bool checkcircular(node *head)
{
    node *temp;
    temp = head->next;
    while (true)
    {
        if (temp == head)
        {
            return true;
        }
        if (temp == NULL)
        {
            return false;
        }
        temp = temp->next;
    }
}

node *insertbeg(node *head, int data)
{
    node *new1 = new node(data);
    node *temp = head->next;
    new1->next = head;


    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = new1;
    head = new1;
    return head;
}
node *insertend(node *head, int data)
{
    node *temp;
    temp = head->next;
    node *new1 = new node(data);
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = new1;
    new1->next = head;

    return head;
}
node *insertafter(node *head, int data, int data1)
{
    node *temp;
    temp = head->next;
    node *new1 = new node(data);
    while (temp->next != head)
    {
        if (temp->data == data1)
        {
            new1->next = temp->next;
            temp->next = new1;
        }
        temp = temp->next;
    }

    return head;
}



node *deletebeg(node *head)
{
    node *temp1;
    node *temp;
    temp1 = head;
    head = head->next;
    free(temp1);
    temp=head;
    while (temp->next != temp1)
    {
        temp = temp->next;
    }
    temp->next=head;
    return head;
}
node *deletelast(node *head)
{
    node *temp;
    node *prev;
    temp = head->next;
    while (temp->next != head)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = head;
    free(temp);
    return head;
}

node *deletedata(node *head, int data)
{
    node *temp;
    node *prev;
    prev=head;
    temp = head->next;

    while (temp->next != head)
    {

        if (temp->data == data)
        {
            prev->next = temp->next;
            free(temp);
        }
        prev = temp;
        temp = temp->next;
    }

    return head;
}



int search(node *head, node *n1)
{
    node *temp;
    if(head->data==n1->data){
        return 1;
    }
    temp = head->next;
    int i = 2;
    while (temp->next!= head)
    {
        if (temp->data == n1->data)
        {
            return i;
        }
        temp = temp->next;
        i++;
    }
    return i;
}

int main()
{

    node *n1 = new node(20);
    node *n2 = new node(100);
    node *n3 = new node(40);
    node *n4 = new node(80);
    node *n5 = new node(60);
    node *head = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n1;
    int i=search(head,n2);
    cout<<i;


    return 0;


}

