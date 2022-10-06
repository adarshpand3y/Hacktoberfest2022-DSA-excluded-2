#include<iostream>
#include<cstdlib>

using namespace std;

struct node
{
    int data;
    node* next;
};

class linkedList
{
    node *head;
public:
    linkedList()
    {
        head = NULL;
    }

    void create_linkedlist()
    {
        int val = 0;
        while(val != -1)
        {
            cout<<"\nEnter a value(-1 to stop): ";
            cin>>val;
            if(val != -1)
            {
                node *newNode = new node;
                newNode->data = val;

               if(head == NULL)
               {
                   head= newNode;
                   newNode->next = NULL;
               }
               else
               {
                   node *ptr = head;
                   while(ptr->next != NULL)
                   {
                       ptr = ptr->next;
                   }
                   ptr->next = newNode;
                   newNode->next = NULL;
               }
            }
        }
    }

    void insert_end_linkedlist(int n)
    {
        node *ptr = head;
        node *newNode = new node;
        newNode->data = n;
        newNode->next = NULL;

        if(head == NULL)
        {
            head= newNode;
        }
        else
        {
            while(ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = newNode;
        }
    }

    void insert_beg_linkedlist(int n)
    {
        node*tmp = new node;
        tmp->data = n;
        tmp-> next = head;
        head = tmp;
    }

    void insert_before_linkedlist(int n, int val)
    {
        node *newNode = new node;
        newNode->data = val;
        if(head->data == n)
        {
            insert_beg_linkedlist(val);
        }
        else
        {
            node *ptr = head;
            node *preptr;

            while(ptr->data != n)
            {
                preptr = ptr;
                ptr = ptr->next;
            }

            preptr->next = newNode;
            newNode->next = ptr;
        }
    }

    void insert_after_linkedlist(int n, int val)
    {
        node *newNode = new node;
        newNode->data = val;
        node *ptr = head;
        while (ptr->data != n)
        {
            ptr = ptr->next;
        }
        newNode->next=ptr->next;
        ptr->next = newNode;
    }

    void delete_beg_linkedlist()
    {
        node *ptr = head;
        head = head->next;
        delete ptr;
    }

    void delete_end_linkedlist()
    {
        node *ptr =head;
        node *preptr = ptr;
        while(ptr->next != NULL)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = NULL;
        delete ptr;
    }

    void delete_node_linkedlist(int n)
    {
        node *ptr = head;
        if(ptr->data == n)
        {
            delete_beg_linkedlist();
        }
        else
        {
            node*preptr = ptr;
            while(ptr->data != n)
            {
                preptr = ptr;
                ptr = ptr->next;
            }
            preptr->next = ptr->next;
            delete ptr;
        }
    }

    void delete_after_linkedlist(int n)
    {
        node *ptr= head;
        while(ptr->data != n)
        {
            ptr = ptr->next;
        }
        if(ptr->next == NULL)
        {
            cout<<endl<<"No node to delete!!"<<endl;
        }
        else
        {
            node *tmp = ptr->next;
            ptr->next = tmp->next;
            delete tmp;
        }
    }

    void delete_linkedlist()
    {
        while(head != NULL)
        {
            delete_beg_linkedlist();
        }
    }

    void display_linkedlist()
    {
        node *ptr = head;
        if(head == NULL)
        {
            cout<<"\nThe list is empty!!"<<endl;
        }
        cout<<endl<<endl;
        while(ptr != NULL)
        {
            cout<<" "<<ptr->data<<" ";
            ptr = ptr->next;
        }
        cout<<endl<<endl;
    }

};

int main()
{
    linkedList listobj;
    int ch;
    do
    {
        cout<<"\n\n*******LINKED LIST*******"<<endl;
        cout<<"\n\n1. Create a linked list."<<endl;
        cout<<"2. Insert at beginningg."<<endl;
        cout<<"3. Insert at end."<<endl;
        cout<<"4. Insert before a node in linked list."<<endl;
        cout<<"5. Insert after a node in linked list."<<endl;
        cout<<"6. Delete beginning of a linked list."<<endl;
        cout<<"7. Delete end of a linked list."<<endl;
        cout<<"8. Delete a node of a linked list."<<endl;
        cout<<"9. Delete after a node of a linked list."<<endl;
        cout<<"10. Delete a linked list."<<endl;
        cout<<"11.Exit"<<endl;
        cout<<"\n\nChoose option: ";
        cin>>ch;

        switch (ch)
        {
        case 1:
        {
            listobj.create_linkedlist();
            break;
        }
        case 2:
        {
            int val;
            cout<<"\nenter the number to insert at the beginning: ";
            cin>>val;
            listobj.insert_beg_linkedlist(val);
            break;
        }

        case 3:
        {
            int val;
            cout<<"\nenter the number to insert at end: ";
            cin>>val;
            listobj.insert_end_linkedlist(val);
            break;
        }
        case 4:
        {
            int n,val;
            cout<<"\nEnter the the node value whose predecessor is to be added: ";
            cin>>n;
            cout<<"Enter the number to insert: ";
            cin>>val;
            listobj.insert_before_linkedlist(n,val);
            break;
        }

        case 5:
        {
            int n,val;
            cout<<"\nEnter the the node value whose successor is to be added: ";
            cin>>n;
            cout<<"Enter the number to insert: ";
            cin>>val;
            listobj.insert_after_linkedlist(n,val);
            break;
        }

        case 6:
        {
            listobj.delete_beg_linkedlist();
            break;
        }

        case 7:
        {
            listobj.delete_end_linkedlist();
            break;
        }

        case 8:
        {
            int n;
            cout<<"\nEnter the node value to delete: ";
            cin>>n;
            listobj.delete_node_linkedlist(n);
            break;
        }

        case 9:
        {
            int n;
            cout<<"\nEnter the node value whose succeeding value is to be deleted: ";
            cin>>n;
            listobj.delete_after_linkedlist(n);
            break;
        }

        case 10:
        {
                listobj.delete_linkedlist();
                break;
        }

        case 11:
        {
            exit(1);
            break;
        }

        default :
        {
            cout<<"Invalid input";
            break;
        }
        }

        listobj.display_linkedlist();
    } while (ch!=11);
    return 0;
}
