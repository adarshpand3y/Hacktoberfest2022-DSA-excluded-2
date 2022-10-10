// C++ program for postorder tree traversal
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
and a pointer to right child */
struct Node {
	int data;
	struct Node *left, *right;
};

// Utility function to create a new tree node
Node* newNode(int data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

/* Given a binary tree, print its nodes in postorder*/
void printpostorder(struct Node* node)
{
	if (node == NULL)
		return;

	/* first recur on left child */
	printpostorder(node->left);

	/* then recur on right child */
	printpostorder(node->right);

    /* now print the data of node */
	cout << node->data << " ";
}

/* Driver code*/
int main()
{
	struct Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	// Function call
	cout << "\nPostorder traversal of binary tree is \n";
	printpostorder(root);

	return 0;
}
