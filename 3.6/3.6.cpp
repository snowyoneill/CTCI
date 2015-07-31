#include <iostream>

#include "myStack.h"

using namespace std;

template <class T>
void sortStack(myStack<T> *org, myStack<T> *buf) //Does not work for 3->2->5 - returns unaltered stack.
{
	bool sorted = false;
	int maxS = org->size;
	T top = org->pop();
	while(!(sorted && org->size == 0))
	{
		T next = org->pop();
		buf->push(next);
		if(top > next)
			sorted = true;
		else
		{
			sorted = false;
			while(org->size != 0)
			{
				next = org->pop();
				buf->push(next);
			}
			buf->push(top);
			while(buf->size != 0)
				org->push(buf->pop());
			top = org->pop();
		}
	}
	while(buf->size != 0)
		org->push(buf->pop());
	org->push(top);
}

template <class T>
void sortStack2(myStack<T> *org, myStack<T> *r)
{
	while(org->size > 0)
	{
		T tmp = org->pop();
		while (r->size > 0 && r->top->data > tmp) {
			org->push(r->pop());				
		}
		r->push(tmp);
	}
}

int main()
{
	myStack<int> *s = new myStack<int>();
	myStack<int> *tmp = new myStack<int>();

	//s->push(4);
	//s->push(1);
	//s->push(2);
	//s->push(3);

	s->push(3);
	s->push(2);
	s->push(5);

	s->printStack();

	sortStack(s, tmp);
	//sortStack2(s, tmp);

	tmp->printStack();

	s->printStack();

	return 0;
}