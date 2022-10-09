#include <bits/stdc++.h>
using namespace std;

struct avlNode
{
    int data;
    avlNode *left;
    avlNode *right;
    int height;
};

int height(avlNode *root)
{
    // Edge case - Root is null
    return (root == NULL ? -1 : root->height);
}

avlNode *singleRightRotate(avlNode *&root)
{
    avlNode *u = root->left;
    root->left = u->right;
    u->right = root;
    root->height = max(height(root->left), height(root->right)) + 1;
    u->height = max(height(u->left), root->height) + 1;
    return u;
}

avlNode *singleLeftRotate(avlNode *&root)
{
    avlNode *u = root->right;
    root->right = u->left;
    u->left = root;
    root->height = max(height(root->left), height(root->right)) + 1;
    u->height = max(height(root->right), root->height) + 1;
    return u;
}

avlNode *doubleLeftRotate(avlNode *&root)
{
    root->right = singleRightRotate(root->right);
    return singleLeftRotate(root);
}

avlNode *doubleRightRotate(avlNode *&root)
{
    root->left = singleLeftRotate(root->left);
    return singleRightRotate(root);
}

avlNode *insert(avlNode *root, int x)
{
    // Root null
    if (root == NULL)
    {
        root = new avlNode;
        root->data = x;
        root->left = NULL;
        root->right = NULL;
        root->height = 0;
    }

    // Root value greater
    else if (root->data > x)
    {
        root->left = insert(root->left, x);

        // Unbalanced on the left side
        if (height(root->left) - height(root->right) == 2)
        {
            if (x < root->left->data)
            {
                root = singleRightRotate(root);
            }

            else
            {
                root = doubleRightRotate(root);
            }
        }
    }

    // Root value lesser
    else
    {
        root->right = insert(root->right, x);

        // Unbalanced on the right side
        if (height(root->right) - height(root->left) == 2)
        {
            if (x > root->right->data)
            {
                root = singleLeftRotate(root);
            }

            else
            {
                root = doubleLeftRotate(root);
            }
        }
    }

    root->height = max(height(root->left), height(root->left)) + 1;
    return root;
}

void display(avlNode *root)
{
    if (root == NULL)
        return;

    display(root->left);
    cout << root->data << " ";
    display(root->right);
}

avlNode *findMin(avlNode *t)
{
    if (t == NULL)
        return NULL;
    else if (t->left == NULL)
        return t;
    else
        return findMin(t->left);
}

avlNode *findMax(avlNode *t)
{
    if (t == NULL)
        return NULL;
    else if (t->right == NULL)
        return t;
    else
        return findMax(t->right);
}

avlNode *remove(avlNode *root, int x)
{

    avlNode *temp;

    // Element not found
    if (root == NULL)
        return NULL;

    // Searching for element
    else if (x < root->data)
        root->left = remove(root->left, x);

    else if (x > root->data)
        root->right = remove(root->right, x);

    // Element found
    // With 2 children
    else if (root->left && root->right)
    {
        temp = findMin(root->right);
        root->data = temp->data;
        root->right = remove(root->right, root->data);
    }

    // With one or zero child
    else
    {
        temp = root;
        if (root->left == NULL)
            root = root->right;
        else if (root->right == NULL)
            root = root->left;
        delete temp;
    }

    if (root == NULL)
        return root;

    root->height = max(height(root->left), height(root->right)) + 1;

    // If node is unbalanced
    // If left node is deleted, right case
    if (height(root->left) - height(root->right) == 2)
    {
        if (height(root->left->left) - height(root->left->right) == 1)
            return singleLeftRotate(root);

        else
            return doubleLeftRotate(root);
    }
    // If right node is deleted, left case
    else if (height(root->right) - height(root->left) == 2)
    {
        if (height(root->right->right) - height(root->right->left) == 1)
            return singleRightRotate(root);

        else
            return doubleRightRotate(root);
    }
    return root;
}

int main()
{

    avlNode *root = NULL;

    // insertion
    root = insert(root, 5);
    root = insert(root, 10);
    root = insert(root, 15);

    // display
    cout<<"Preorder traversal - "; display(root);
    cout << endl;

    // insertion
    root = insert(root, 20);

    // removal
    root = remove(root, 5);
    root = remove(root, 15);

    cout<<"Preorder traversal - "; display(root);
    cout << endl;
}