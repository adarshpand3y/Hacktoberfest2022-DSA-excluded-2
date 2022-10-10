#include <iostream>
#include <queue>
using namespace std;


// making the  binarytreenode class for node of the tree//
template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

// taking binary tree input (e.g 1 2 3 -1 -1 -1 -1 ) -1 denotes that 2 and 3 are leaf nodes 
BinaryTreeNode<int>* takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

//  function for preorder traversal with the help of recursion//
void preOrder(BinaryTreeNode<int> *root) {
	if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

//  function for postorder traversal with the help of recursion//
void postOrder(BinaryTreeNode<int> *root) {
	if(root==NULL)
    {
        return;
    }
    
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}


int main() {
    BinaryTreeNode<int>* root = takeInput();
    preOrder(root);
    cout<<endl;
    postOrder(root);
}
