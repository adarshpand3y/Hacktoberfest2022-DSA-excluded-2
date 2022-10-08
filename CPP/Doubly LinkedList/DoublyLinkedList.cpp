#include <iostream>

using namespace std;

struct Node {
    public: int data;
    Node * next;
    Node * prev;

    Node(int value) {
        data = value;
        next = NULL;
        prev = NULL;
    }
    void display() {
        cout << " The Roll No is : " << data << endl;
    }

};

class DoublyList {
    private:
        Node * head;
    Node * tail;
    public:
        DoublyList() {
            head = NULL;
            tail = NULL;
        }
    insertAtHead(Node * i) {
        if (head == NULL && tail == NULL) {
            head = i;
            tail = i;
        } else {
            i -> next = head;
            head -> prev = i;
            head = i;
        }
    }

    insertAtTail(Node * i) {
        if (head == NULL && tail == NULL) {
            head = i;
            tail = i;
        } else {
            tail -> next = i;
            i -> prev = tail;
            tail = i;
        }
    }

    delAtHead() {
        if (head == NULL && tail == NULL) {
            cout << " the list is empty !" << endl;
        } else if (head == tail) {
            head = NULL;
            tail = NULL;
        } else {
            Node * curr = head;
            head = head -> next;
            delete curr;
        }
    }

    delAtTail() {
        if (head == NULL && tail == NULL) {
            cout << " the list is empty !" << endl;
        } else if (head == tail) {
            head = NULL;
            tail = NULL;
        } else {
            Node * curr = tail;
            tail = tail -> prev;
            delete curr;
        }
    }
    void search(int key) {
        int i = 0;
        if (head == NULL && tail == NULL) {
            cout << " List is empty " << endl;
        } else {
            Node * curr = head;
            while (curr != NULL) {
                if (curr -> data == key) {
                    cout << " The value found : " << curr -> data << endl;
                    curr = curr -> next;
                    i++;
                }
            }
        }
        if (i == 0) {
            cout << " The does not found...!" << endl;
        }
    }
    displayList() {
        if (head == NULL && tail == NULL) {
            cout << " The list is empty nothing to show" << endl;
        } else {
            Node * curr = head;
            while (curr != NULL) {
                cout << " The Roll No is : " << curr -> data << endl;
                curr = curr -> next;
            }
        }
    }
};

int main() {

    DoublyList * list = new DoublyList();
    Node * n1 = new Node(22);
    list -> insertAtHead(n1);
    list -> insertAtHead(new Node(44));
    list -> insertAtHead(new Node(33));
    list -> insertAtTail(new Node(45));
    n1 -> display();
    cout << " Before the deletion process: " << endl;
    list -> displayList();

    list -> delAtHead();
    list -> delAtTail();
    cout << "After the deletion process" << endl;
    list -> displayList();
    return 0;

}