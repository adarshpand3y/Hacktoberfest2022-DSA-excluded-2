//author : Santanu Jana

#include <bits/stdc++.h>
using namespace std;
  
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
  
int main()
{
    Node* root = new Node(5);
    root->left = new Node(8);
    root->right = new Node(10);
    root->left->left = new Node(4);
    return 0;
}

// The tree will look like :-     5
//                               / \
//                             8     10
//                            /
//                           4