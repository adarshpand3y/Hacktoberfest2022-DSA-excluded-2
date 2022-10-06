#include<iostream>
#include<cstdlib>
using namespace std;
struct node
{
    int data;
    node* next;
    node* prev;
};
class dlinkedlist
{
    node *head;
public:
    dlinkedlist()
    {
        head = NULL;
    }
    void create_dlinkedlist()
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
                   newNode->prev = NULL;
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
                   newNode->prev = ptr;
               }
            }
        }
    }
    void insert_end_dlinkedlist(int n)
    {
        node *ptr = head;
        node *newNode = new node;
        newNode->data = n;
        newNode->next = NULL;

        if(head == NULL)
        {
            head= newNode;
            newNode->prev = NULL;
        }
        else
        {
            while(ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = newNode;
            newNode->prev = ptr;
        }
    }

    void insert_beg_dlinkedlist(int n)
    {
        node*tmp = new node;
        tmp->data = n;
        tmp-> next = head;
        head->prev = tmp;
        tmp->prev = NULL;
        head = tmp;
    }

    void insert_before_dlinkedlist(int n, int val)
    {
        if(head->data == n)
        {
            insert_beg_dlinkedlist(val);
        }
        else
        {
            node *newNode = new node;
            newNode->data = val;
            node *ptr = head;
            while(ptr->data != n)
            {
                ptr = ptr->next;
            }
            newNode->prev = ptr->prev;
            ptr->prev->next = newNode;
            newNode->next = ptr;
            ptr->prev = newNode;
        }
    }

    void insert_after_dlinkedlist(int n, int val)
    {
        node *newNode = new node;
        newNode->data = val;
        node *ptr = head;
        while (ptr->data != n)
        {
            ptr = ptr->next;
        }
        if(ptr->next == NULL)
        {
            newNode->prev = ptr;
            ptr->next = newNode;
            newNode->next = NULL;
        }
        else
        {
            newNode->next = ptr->next;
            ptr->next->prev = newNode;
            newNode->prev = ptr;
            ptr->next = newNode;
        }
    }

    void delete_beg_dlinkedlist()
    {
        if(head == NULL)
        {
            cout<<"\nList is empty!!\n";
        }
        else
        {
            node *ptr = head;
            if(head->next == NULL)
            {
                head = NULL;
            }
            else
            {
                head = head->next;
                head->prev = NULL;
                delete ptr;
            }
        }
    }

    void delete_end_dlinkedlist()
    {
        node *ptr =head;
        while(ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        if(ptr == head)
        {
            cout<<"\nList is empty!!\n";
        }
        else
        {
            ptr->prev->next = NULL;
            delete ptr;
        }
    }

    void delete_node_dlinkedlist(int n)
    {
        node *ptr = head;
        while(ptr->data != n)
        {
            ptr = ptr->next;
        }
        if(ptr == head)
        {
            delete_beg_dlinkedlist();
        }
        else if(ptr->next == NULL)
        {
            delete_end_dlinkedlist();
        }
        else
        {
            ptr->prev->next = ptr->next;
            ptr->next->prev = ptr->prev;
            delete ptr;
        }
    }

    void delete_before_dlinkedlist(int n)
    {
        node *ptr= head;
        if(ptr->data == n)
        {
            cout<<"\nNo node to delete!\n";
        }
        else
        {
            while(ptr->next->data != n)
            {
                ptr = ptr->next;
            }
            if(ptr->data == head->data)
            {
                ptr->next->prev = NULL;
                head = ptr->next;
                delete ptr;
            }
            else
            {
                ptr->prev->next = ptr->next;
                ptr->next->prev = ptr->prev;
                delete ptr;
            }
        }
    }

    void delete_after_dlinkedlist(int n)
    {
        node *ptr= head;
        while(ptr->data != n)
        {
            ptr = ptr->next;
        }
        if(ptr->next == NULL)
        {
            cout<<"\nNO node to delete after\n";
        }
        else
        {
            ptr = ptr->next;
            if(ptr->next == NULL)
            {
                delete_end_dlinkedlist();
            }
            else
            {
                ptr->prev->next = ptr->next;
                ptr->next->prev = ptr->prev;
                delete ptr;
            }
        }
    }

    void delete_dlinkedlist()
    {
        while(head->next != NULL)
        {
            delete_beg_dlinkedlist();
        }
        delete_beg_dlinkedlist();
    }

    void display_dlinkedlist()
    {
        node *ptr = head;
        if(head == NULL)
        {
            cout<<"\nThe list is empty!!"<<endl;
        }
        else
        {
            cout<<"List:\n";
            while(ptr != NULL)
            {
                cout<<" "<<ptr->data<<" ";
                ptr = ptr->next;
            }
            cout<<endl<<endl;
        }
    }

};

int main()
{
    dlinkedlist listobj;
    int choose;
    do
    {
        cout<<"\n\n1.  Create a doubly linked list."<<endl;
        cout<<"2.  Insert a node at beginningg."<<endl;
        cout<<"3.  Insert a node at end."<<endl;
        cout<<"4.  Insert a node before a given node."<<endl;
        cout<<"5.  Insert a node after a given node."<<endl;
        cout<<"6.  Delete a node at beginning."<<endl;
        cout<<"7.  Delete a node at last."<<endl;
        cout<<"8.  Delete a given node."<<endl;
        cout<<"9.  Delete a node before a given node."<<endl;
        cout<<"10. Delete a node after a given node."<<endl;
        cout<<"11. Delete the entire doubly linked list."<<endl;
        cout<<"12. Exit"<<endl;
        cout<<"\n\n\tChoose an option: ";
        cin>>choose;

        switch (choose)
        {
        case 1:
        {
            listobj.create_dlinkedlist();
            break;
        }
        case 2:
        {
            int val;
            cout<<"\nenter the number to insert at the beginning: ";
            cin>>val;
            listobj.insert_beg_dlinkedlist(val);
            break;
        }

        case 3:
        {
            int val;
            cout<<"\nenter the number to insert at end: ";
            cin>>val;
            listobj.insert_end_dlinkedlist(val);
            break;
        }
        case 4:
        {
            int n,val;
            cout<<"\nEnter the the node value whose predecessor is to be added: ";
            cin>>n;
            cout<<"Enter the number to insert: ";
            cin>>val;
            listobj.insert_before_dlinkedlist(n,val);
            break;
        }
        case 5:
        {
            int n,val;
            cout<<"\nEnter the the node value whose successor is to be added: ";
            cin>>n;
            cout<<"Enter the number to insert: ";
            cin>>val;
            listobj.insert_after_dlinkedlist(n,val);
            break;
        }

        case 6:
        {
            listobj.delete_beg_dlinkedlist();
            break;
        }

        case 7:
        {
            listobj.delete_end_dlinkedlist();
            break;
        }
        case 8:
        {
            int n;
            cout<<"\nEnter the node value to delete: ";
            cin>>n;
            listobj.delete_node_dlinkedlist(n);
            break;
        }

        case 9:
        {
            int n;
            cout<<"\nEnter the node value whose preceeding value is to be deleted: ";
            cin>>n;
            listobj.delete_before_dlinkedlist(n);
            break;
        }

        case 10:
        {
            int n;
            cout<<"\nEnter the node value whose succeeding value is to be deleted: ";
            cin>>n;
            listobj.delete_after_dlinkedlist(n);
            break;
        }

        case 11:
        {
                listobj.delete_dlinkedlist();
                break;
        }

        case 12:
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
        listobj.display_dlinkedlist();
    } while (choose!=12);

    return 0;
} 
