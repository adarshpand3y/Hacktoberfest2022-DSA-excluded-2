//Post-order traversal using Recursion

#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	struct node *left, *right;
};

void postOrderTrav(node *curr, std::vector<int> &postOrder)
{
	//base case
	if (curr == NULL)
		return;

	postOrderTrav(curr -> left, postOrder);
	postOrderTrav(curr -> right, postOrder);
	postOrder.push_back(curr->data);
}

struct node * newNode(int data)
{
	struct node * node = (struct node *) malloc(sizeof(struct node));

	node->data = data;
	node -> left = NULL;
	node -> right = NULL;

	return (node);


};

int main()
{
	struct node *root = newNode(1);
	root -> left = newNode(2);
	root -> right = newNode(3);
	root -> left -> left = newNode(4);
	root -> left -> right = newNode(5);
	root -> left -> right -> left = newNode(8);
	root -> right -> left = newNode(6);
	root -> right -> right = newNode(7);
	root -> right -> right -> left = newNode(9);
	root -> right -> right -> right = newNode(10);

	std::vector<int> postOrder;
	postOrderTrav(root, postOrder);

	cout << "The postOrder Traversal is :";
	for (int i = 0; i < postOrder.size(); i++)
		cout << postOrder[i] << " ";

	return 0;
}