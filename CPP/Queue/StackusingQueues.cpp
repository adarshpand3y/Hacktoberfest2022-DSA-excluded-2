#include<bits/stdc++.h>
using namespace std;

class Stack
{
	queue<int>q;
public:
	void push(int val);
	void pop();
	int top();
	bool empty();
};

void Stack::push(int val)
{
	int s = q.size();

	q.push(val);

	for (int i=0; i<s; i++)
	{
		q.push(q.front());
		q.pop();
	}
}

void Stack::pop()
{
	if (q.empty())
		cout << "No elements\n";
	else
		q.pop();
}

int Stack::top()
{
	return (q.empty())? -1 : q.front();
}

bool Stack::empty()
{
	return (q.empty());
}

int main()
{
	Stack s;
	s.push(10);
	s.push(20);
	cout << s.top() << endl;
	s.pop();
	s.push(30);
	s.pop();
	cout << s.top() << endl;
	return 0;
}
