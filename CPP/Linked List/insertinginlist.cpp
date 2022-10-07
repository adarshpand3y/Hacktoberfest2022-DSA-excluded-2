#include <iostream>
#include<algorithm>
 #include<numeric>
using namespace std;


struct node{
	int info;
	struct node *next;
};
struct node *first,*last,*t;



void insert(int pos,int data){
	struct node *t,*p;
	if(pos==0){
t=new node;
t->info=data;
t->next=first;
first=t;

	}
	else{
		p=first;
		for(int i=0;i<pos-1;i++){
 p=p->next;
		}
		t=new node;
 t->info=data;
 t->next=p->next;
 p->next=t;
	}
}



void insertlast(int x){
	node *last,*t;
	t=new node;//creating new node to be added
	t->info=x;
	t->next=NULL;//creating new node to be added
	if(first==NULL){
    first=last=t;//if no node present then first and last points to t(newly created)
	}
	else{
		last=first;//start last from where first points
		while(last->next!=NULL){
			last=last->next;//finding last node
		}
		last->next=t;//pointing the last pointer to last node
		last=t;
	}

}


void insertsorted(int x){//insert at sorted position
	node *p,*q;
	p=first;//1st pointer to first
	q=NULL;
	while(p!=NULL && p->info<x){//finding last node
q=p;//2nd pointer follows 1st
p=p->next;
	}
	t=new node;
	t->info=x;
	t->next=q->next;
	q->next=t;
	}




void display(struct node *first){
	while(first!=NULL){
		cout<<first->info<<endl;
		first=first->next;
	}
}


int main() {
	int arr[6]={1,2,3,4,5,6};//creating linked list
	
	first=new node;
	first->info=arr[0];
	first->next=NULL;
	last=first;

	for(int i=1;i<6;i++){
		t=new node;
		
		t->info=arr[i];
		t->next=NULL;
		last->next=t;
		last=t;//creating linked list
    
    
    
    insert(0,100);
    insertsorted(3);
	  insertlast(5000);
	  display(first);

	}

