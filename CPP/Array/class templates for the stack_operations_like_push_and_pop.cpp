//a c++ program for creating a stack template and use basic operations like push and pop..

#include<iostream>
using namespace std;

//we are creating a stack template where we will do push operation and pop operation
template<typename T>
class stack{
	private:
	int top;
	T arr[10];
	public:
	stack(){
		top=-1;
	}
	void push(T a);
	T pop();
};
//we are trying to define push() operations..
//as usual, we check if stack is full, if not then insert the element
template<typename T>
void stack<T> :: push(T a){
	if(top>=10){
		cout<<"Stack Full"<<endl;
		return;
	}
	top++;
	arr[top]=a;
}
//we are trying to define pop() operations
//if stack is not empty, the pop operation is performed

template<typename T>
T stack<T> :: pop(){
	if(top==-1){
		cout<<"Invalid Operation!! Stack Empty"<<endl;
	}
	return arr[top--];
}

//main program with understandable test cases

int main(){
  //creating a stack template
	stack<int> s;
  //push operations
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	s.push(2);
	s.push(3);
	s.push(4);
  //pop operations
	cout<<s.pop()<<endl;
	cout<<s.pop()<<endl;
	cout<<s.pop()<<endl;
	cout<<s.pop()<<endl;
	cout<<s.pop()<<endl;
	cout<<s.pop()<<endl;
	cout<<s.pop()<<endl;
	cout<<s.pop()<<endl;
	return 0;

}
