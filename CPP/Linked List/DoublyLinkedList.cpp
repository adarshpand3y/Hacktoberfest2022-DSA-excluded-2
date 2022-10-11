// Inserting node in doubly linked list

#include<bits/stdc++.h>

using namespace std;

struct Node {
   int data;
   struct Node* next;
   struct Node* prev;
};
  
//inserts node at the front of the list
void insert_front(struct Node** head, int new_data)
{
   struct Node* newNode = new Node;
  
   newNode->data = new_data;
  
   newNode->next = (*head);
   newNode->prev = NULL;
  
   if ((*head) != NULL)
   (*head)->prev = newNode;
  
   (*head) = newNode;
}
  
//insert a new node at the end of the list
void insert_end(struct Node** head, int new_data)
{
   //allocate memory for node
   struct Node* newNode = new Node;
  
   struct Node* last = *head; 
  
   newNode->data = new_data;
  
   newNode->next = NULL;
  
   if (*head == NULL) {
   newNode->prev = NULL;
   *head = newNode;
    return;
}
  
while (last->next != NULL)
last = last->next;
  
last->next = newNode;
  
newNode->prev = last;
return;
}
  
void displayList(struct Node* node) {
   struct Node* last;
  
   while (node != NULL) {
      cout<<node->data<<"<-->";
      last = node;
      node = node->next;
   }
   if(node == NULL)
   cout<<"NULL";
   }
  
int main() {
   struct Node* head = NULL;
  
   insert_end(&head, 10);
  
   insert_front(&head, 30);
  
   insert_front(&head, 40);
  
   insert_end(&head, 50);
    
   cout<<"Doubly linked list is as follows: "<<endl;
   displayList(head);
   return 0;
}
