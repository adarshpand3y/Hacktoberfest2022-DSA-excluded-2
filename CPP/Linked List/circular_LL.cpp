#include<iostream>
#include<cstdlib>
using namespace std;
struct node
{
    int data;
    node* next;
};
class clinkedlist
{
    node *head;
public:
    clinkedlist()
    {
        head = NULL;
    }

    void create_clinkedlist()
    {
        int val = 0;
        while(val != -1)
        {
            cout<<"\nEnter a value: ";
            cin>>val;
            if(val != -1)
            {
                node *newNode = new node;
                newNode->data = val;

               if(head == NULL)
               {
                   head= newNode;
                   newNode->next = head;
               }
               else
               {
                   node *ptr = head;
                   while(ptr->next != head)
                   {
                       ptr = ptr->next;
                   }
                   ptr->next = newNode;
                   newNode->next = head;
               }
            }
        }
    }
    void insert_end_clinkedlist(int n)
    {
        node *ptr = head;
        node *newNode = new node;
        newNode->data = n;
        newNode->next = head;

        if(head == NULL)
        {
            head= newNode;
        }
        else
        {
            while(ptr->next != head)
            {
                ptr = ptr->next;
            }
            ptr->next = newNode;
            newNode->next = head;
        }
    }
    void insert_beg_clinkedlist(int n)
    {
        node *newNode = new node;
        newNode->data = n;
        newNode->next = head;
        node *ptr = head;
        while(ptr->next != head)
        {
            ptr = ptr->next;
        }
        ptr->next = newNode;
        head = newNode;
    }
    void insert_before_clinkedlist(int n, int val)
    {
        node *newNode = new node;
        newNode->data = val;
        if(head->data == n)
        {
            insert_beg_clinkedlist(val);
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
    void insert_after_clinkedlist(int n, int val)
    {
        node *newNode = new node;
        newNode->data = val;

        node *ptr = head;
        while (ptr->data != n)
        {
            ptr = ptr->next;
        }
        if(ptr->next == head)
        {
          ptr->next = newNode;
          newNode->next = head;
        }
        else
        {
            newNode->next=ptr->next;
            ptr->next = newNode;
        }
    }

    void delete_beg_clinkedlist()
    {
        if(head->next == head)
        {
            head = NULL;
        }
        else
        {
            node *ptr = head;
            node *tmp = head;
            while(ptr->next != head)
            {
                ptr = ptr->next;
            }
            ptr->next = head->next;
            head = head->next;
            delete tmp;
        }
    }
    void delete_end_clinkedlist()
    {
        node *ptr =head;
        node *preptr = ptr;
        while(ptr->next != head)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = head;
        delete ptr;
    }
    void delete_node_clinkedlist(int n)
    {
        node *ptr = head;
        if(ptr->data == n)
        {
            delete_beg_clinkedlist();
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
    void delete_after_clinkedlist(int n)
    {
        node *ptr= head;
        while(ptr->data != n)
        {
            ptr = ptr->next;
        }
        if(ptr->next == head)
        {
            delete_beg_clinkedlist();
        }
        else
        {
            node *tmp = ptr->next;
            ptr->next = tmp->next;
            delete tmp;
        }
    }

    void delete_clinkedlist()
    {
        while(head != NULL)
        {
            delete_beg_clinkedlist();
        }
    }
    void display_clinkedlist()
    {
        node *ptr = head;
        if(head == NULL)
        {
            cout<<"\nThe list is empty!!"<<endl;
        }
        else
        {
            cout<<endl<<endl<<"Head: "<<head->data<<endl;
            while(ptr->next != head)
            {
                cout<<" "<<ptr->data<<" ";
                ptr = ptr->next;
            }
            cout<<" "<<ptr->data<<" ";
            cout<<endl<<endl;
        }
    }

};
int main()
{
    clinkedlist listobj;
    int choose;
    do
    {
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
        cout<<"\n\nChoose an option: ";
        cin>>choose;
        switch (choose)
        {
        case 1:
        {
            listobj.create_clinkedlist();
            break;
        }
        case 2:
        {
            int val;
            cout<<"\nenter the number to insert at the beginning: ";
            cin>>val;
            listobj.insert_beg_clinkedlist(val);
            break;
        }
        case 3:
        {
            int val;
            cout<<"\nenter the number to insert at end: ";
            cin>>val;
            listobj.insert_end_clinkedlist(val);
            break;
        }
        case 4:
        {
            int n,val;
            cout<<"\nEnter the the node value whose predecessor is to be added: ";
            cin>>n;
            cout<<"Enter the number to insert: ";
            cin>>val;
            listobj.insert_before_clinkedlist(n,val);
            break;
        }

        case 5:
        {
            int n,val;
            cout<<"\nEnter the the node value whose successor is to be added: ";
            cin>>n;
            cout<<"Enter the number to insert: ";
            cin>>val;
            listobj.insert_after_clinkedlist(n,val);
            break;
        }

        case 6:
        {
            listobj.delete_beg_clinkedlist();
            break;
        }

        case 7:
        {
            listobj.delete_end_clinkedlist();
            break;
        }

        case 8:
        {
            int n;
            cout<<"\nEnter the node value to delete: ";
            cin>>n;
            listobj.delete_node_clinkedlist(n);
            break;
        }

        case 9:
        {
            int n;
            cout<<"\nEnter the node value whose succeeding value is to be deleted: ";
            cin>>n;
            listobj.delete_after_clinkedlist(n);
            break;
        }

        case 10:
        {
                listobj.delete_clinkedlist();
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
        system("CLS");
        listobj.display_clinkedlist();
    } while (choose!=11);

    return 0;
}
