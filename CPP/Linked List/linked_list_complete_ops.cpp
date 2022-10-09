#include<iostream>
#include<cstdio>
using namespace std;
class Node{
    public:
       int key;
       Node* next;
};
class List{
    private:
    Node *head, *tail;
    public:
    List(){
        head = NULL;
        tail = NULL;   
    }
    void InsertBegin(int key){
        Node* new_node = new Node();
        if(head == NULL && tail == NULL){
            new_node-> key = key;
            head = new_node;
            tail = new_node;
        }
    new_node-> key = key;
    tail-> next = new_node;
    tail = new_node;
   }
    void InsertEnd(int key){
        Node* new_node = new Node();
        if(head == NULL && tail == NULL){
            new_node-> key = key;
            head = new_node;
            tail = new_node;
        }
    new_node-> key = key;
    new_node-> next = head;
    head = new_node;
    }
    void InsertSpecific(int key,int val){
        Node* new_node = new Node();
        Node * track = head;
        while (track!=NULL){
            if(track-> key == key)
                break;
            track = track->next;
        }
    new_node-> key = val;
    new_node-> next = track->next;
    track->next = new_node;
    }
    int DeleteBegin(){
        if(head == NULL){
            return -1;
        }
        int item = head->key;
        Node* Temp = head;
        head = head->next;
        delete(Temp);// Clearing Memory 
        return item;
    }  
    int DeleteEnd(){
        if(head == NULL){
            return -1;
        }
        Node * track = head;
        while ((track->next)->next!=NULL){
            track = track->next;
        }
        int item = tail->key;
        Node* Temp = tail;
        tail = track;
        track->next = NULL;
        delete(Temp);// Clearing Memory 
        return item;
    }
    void DeleteSpecific(int k){
        if(head == NULL){   
        }
        Node * track = head;
        while (track!=NULL){
            if((track->next)->key == k)
                break;
            track = track->next;
        }
        Node* Temp = track->next;
        track->next = (track->next)->next;
        delete(Temp);// Clearing Memory         
    }

    void Traverse(){
        Node * track = head;
        while (track!=NULL){  
            cout<<track->key;
            track = track->next;
        }
    }
};
int main(){
    List list;
    char ch;int num;
    bool flag=false;
    while(flag){
        cout<<"Choose Operation:"<<endl;;
    	cout<<"1.) Insert"<<endl;
   	 	cout<<"2.) Delete"<<endl;
    	cout<<"3.) Traverse"<<endl;
        cin>>ch;
        if(ch=='1'){
            cout<<"Choose Operation:"<<endl;;
            cout<<"1.) InsertBegin"<<endl;
            cout<<"2.) InsertEnd"<<endl;
            cout<<"3.) InsertSpecific"<<endl;
            cin>>ch;
            if(ch=='1'){
                cin>>num;
                list.InsertBegin(num);
            }
            if(ch=='2'){
                cin>>num;
                list.InsertEnd(num);
            }
            if(ch=='3'){
                cin>>num;
                int temp;cin>>temp;
                list.InsertSpecific(temp,num);
            }
        }
        else if(ch=='2'){      
            cout<<"Choose Operation:"<<endl;;
            cout<<"1.) DeleteBegin"<<endl;
            cout<<"2.) DeleteEnd"<<endl;
            cout<<"3.) DeleteSpecific"<<endl;
            cin>>ch;
            if(ch=='1'){
                list.DeleteBegin();
            }
            if(ch=='2'){
                list.DeleteEnd();
            }
            if(ch=='3'){

                int temp;cin>>temp;
                list.DeleteSpecific(temp);
            }
        }
        else if(ch=='3'){
            list.Traverse();
            cout<<endl;
        }
        else{
            flag = false;
            break;
        }   
    } 
}
