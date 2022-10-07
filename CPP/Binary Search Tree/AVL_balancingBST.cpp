#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Struct for the node defined
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Print BST inorder - iteratively
void inOrder(Node *root)
{
    if (!root)
    {
        return;
    }
    else
    {
        inOrder(root->left);
        cout << root->data;
        inOrder(root->right);
    }
}

// Perform right rotation on a node.
Node *rightRotation(Node *root)
{
    Node *x = root->left;
    Node *temp = x->right;
    if (x)
    {
        x->right = root;
        root->left = temp;
        return x;
    }
    return root;
}

// Perform left rotation on a node
Node *leftRotation(Node *root)
{

    Node *x = root->right;
    Node *temp = x->left;
    if (x)
    {
        x->left = root;
        root->right = temp;
        return x;
    }
    return root;
}

// Find height of the tree
int height(Node *root)
{
    if (!root)
    {
        return 0;
    }
    return (max(height(root->left), height(root->right)) + 1);
}

// Get the balance factor at a node.
int balanceFactor(Node *root)
{
    if (!root)
    {
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);
    return (left - right);
}

// Insert the node in tree and balance the tree if it gets out of balance at any point.
Node *insert(Node *r, Node *insertNode)
{
    if (!r)
    {
        r = insertNode;
        return r;
    }

    if (insertNode->data > r->data)
    {
        r->right = insert(r->right, insertNode);
    }
    else if (insertNode->data < r->data)
    {
        r->left = insert(r->left, insertNode);
    }
    else
    {
        cout << "Can't add duplicate values" << endl;
        return r;
    }

    int bf = balanceFactor(r);

    if (bf > 1 && r->left->data > insertNode->data)
    {
        return rightRotation(r);
    }
    if (bf < -1 && r->right->data < insertNode->data)
    {
        return leftRotation(r);
    }
    if (bf > 1 && r->left->data < insertNode->data)
    {
        r->left = leftRotation(r->left);
        return rightRotation(r);
    }
    if (bf < -1 && r->right->data > insertNode->data)
    {
        r->right = rightRotation(r->right);
        return leftRotation(r);
    }

    return r;
}

int main(int argc, char const *argv[])
{
    Node *root = NULL;
    root = insert(root, new Node(1));
    root = insert(root, new Node(7));
    root = insert(root, new Node(3));
    root = insert(root, new Node(14));
    root = insert(root, new Node(5));
    root = insert(root, new Node(6));
    root = insert(root, new Node(4));
    root = insert(root, new Node(2));
    root = insert(root, new Node(0));

    inOrder(root);
    return 0;
}