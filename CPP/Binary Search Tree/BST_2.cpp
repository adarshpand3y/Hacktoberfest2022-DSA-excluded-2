//author : javali-M
//BST- To check whether a tree is a valid binary search tree or not
/* Consider the following tree:

      20
     /  \
   10    30
        /  \
       5    40
In this tree, each node contains a value larger than its left child and smaller than its right child,
which means the BST condition is satisfied but this is still not a BST.
Notice the value 5 which is less than 20 in the right subtree, a violation of the BST property.
So instead of deciding based solely on a node’s values and its children, we also need information of the parent. 
*/
#include <iostream>
#include <climits>
using namespace std;
 struct Node
{
    int data;
    Node* left = nullptr; 
    Node* right = nullptr;
    Node() {}
    Node(int data): data(data) {}
};
 
//To insert node into the BST
Node* insert(Node* root, int val)
{
    // if root is NULL
    if (root == nullptr) {
        return new Node(val);
    }
    // if val is less than the root recur for left subtree
    if (val < root->data) {
        root->left = insert(root->left, val);
    }
    // if val is more than the root recur for right subtree
    else {
        root->right = insert(root->right, val);
    }
    return root;
}
 
// Check if valid BST or not, using valid range [-INFINITY, INFINITY]
bool checkBST(Node* node, int minval, int maxval)
{
    // base case
    if (node == nullptr) {
        return true;
    }

    // if node is not in the valid range
    if (node->data < minval || node->data > maxval) {
        return false;
    }
 
    // recursively check left and right subtrees with an updated range
    return checkBST(node->left, minval, node->data) && checkBST(node->right, node->data, maxval);
}
 
// Function to determine whether a given binary tree is a BST
void checkBST(Node* root)
{
    if (checkBST(root, INT_MIN, INT_MAX)) {
        cout<<"This tree is a BST."<<endl;
    }
    else {
        cout<<"This tree is not a BST."<<endl;
    }
}
int main()
{
    int arr[] = { 15, 10, 20, 8, 12, 16, 25 };
    Node* root = nullptr;
    for (int val: arr) {
        root = insert(root, val);
    }
    // swap nodes
    //swap(root->left, root->right);
    checkBST(root);
    return 0;
}