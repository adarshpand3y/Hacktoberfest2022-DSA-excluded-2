//author : Shovit Nepal
//Menu driven program for BST-Implementaion
#include <iostream>
#include <string>
using namespace std;
static string path = "";
struct node
{
    int data;
    node *left;
    node *right;
};

class binTree
{
public:
    node *root;
    binTree()
    {
        root = NULL;
    }
    void create_binTree()
    {
        int val;
        do
        {
            cout<<"    Enter the value: ";
            cin>>val;
            if(val == -1)
            {
                break;
            }
            insert_data(val, root);
        } while (val != -1);

    }
    void insert_data(int val, node *ptr)
    {
        if(root == NULL)
        {
            node *newNode = new node;
            newNode->data = val;
            newNode->left = NULL;
            newNode->right = NULL;
            root = newNode;
        }
        else if(ptr->data <= val)
        {
            if(ptr->right == NULL)
            {
                node *newNode = new node;
                newNode->data = val;
                newNode->left = NULL;
                newNode->right = NULL;
                ptr->right = newNode;
            }
            else
                {
                    insert_data(val, ptr->right);
                }
        }
        else
        {
            if(ptr->left == NULL)
            {
                node *newNode = new node;
                newNode->data = val;
                newNode->left = NULL;
                newNode->right = NULL;
                ptr->left = newNode;
            }
            else
                {
                    insert_data(val, ptr->left);
                }
        }
    }

    void search_btree(int val, node *ptr)
    {
        if(ptr->data == val)
        {
            cout<<"\n   The number "<<val<<" is in the tree."<<endl;
            cout<<"   Path : "<<path<<endl;
        }
        else if(ptr == NULL)
        {
            cout<<"   The number doesn't exist."<<endl;
        }
        else if(val < ptr->data)
        {
            path += "Left ";
            search_btree(val, ptr->left);
        }
        else
        {
            path += "Right ";
            search_btree(val, ptr->right);
        }
    }

    void inOrderTrav(node *ptr)
    {
        if(ptr != NULL)
        {
            inOrderTrav(ptr->left);
            cout<<ptr->data<<" ";
            inOrderTrav(ptr->right);
        }
    }

    void postOrderTrav(node *ptr)
    {
        if(ptr != NULL)
        {
            postOrderTrav(ptr->left);
            postOrderTrav(ptr->right);
            cout<<ptr->data<<" ";
        }
    }

    void preOrderTrav(node *ptr)
    {
        if(ptr != NULL)
        {
            cout<<ptr->data<<" ";
            preOrderTrav(ptr->left);
            preOrderTrav(ptr->right);
        }
    }
    void delete_btree(node* &r,int &val)
    {
        if(r==NULL)
            cout<<"\n\n"<<val<<"  is not present in the BST.\n";
        else if(val<r->data)
            delete_btree(r->left,val);
        else if(val>r->data)
            delete_btree(r->right,val);
        else if(r->left && r->right)
        {
            node *t;
            t=LargestNode(r->left);
            r->data=t->data;
            delete_btree(r->left,t->data);
        }
        else
        {
            node *t;
            t=r;
            if(r->left==NULL &&r->right==NULL)
                r=NULL;
            else if(r->left!=NULL)
                r=r->left;
            else
                r=r->right;
            delete t;
        }
    }
    node * LargestNode(node* &l)
    {
        if(l->right==NULL)
            return l;
        else
            return LargestNode(l->right);
    }
};

int main()
{
    binTree tree1;
    int choice;
    do
    {
        cout<<"\n\n1. Create Binary Tree.\n";
        cout<<"2. Insert a number.\n";
        cout<<"3. Search a number.\n";
        cout<<"4. In-order display.\n";
        cout<<"5. Post-order display.\n";
        cout<<"6. Pre-order display.\n";
        cout<<"7. Delete a number.\n";
        cout<<"8. Exit\n";
        cout<<"   Enter your choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1:
            {
                tree1.create_binTree();
                break;
            }
            case 2:
            {
                int val;
                cout<<endl<<"   Enter the number to insert: ";
                cin>>val;
                tree1.insert_data(val,tree1.root);
                break;
            }
            case 3:
            {
                int val;
                cout<<endl<<"   Enter the number to search: ";
                cin>>val;
                path = "";
                tree1.search_btree(val, tree1.root);
                break;
            }
            case 4:
            {
                tree1.inOrderTrav(tree1.root);
                cout<<endl;
                break;
            }
            case 5:
            {
                tree1.postOrderTrav(tree1.root);
                cout<<endl;
                break;
            }
             case 6:
            {
                tree1.preOrderTrav(tree1.root);
                cout<<endl;
                break;
            }
            case 7:
            {
                int val;
                cout<<"   Enter the number to delete: ";
                cin>>val;
                tree1.delete_btree(tree1.root, val);
            }
            case 8:
            {
                break;
            }
            default:
            {
                cout<<endl<<"   !!!Invalid input!!!\n\n";
                break;
            }
        }
    }while(choice != 8);
    return 0;
}
