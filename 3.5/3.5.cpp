#include <iostream>

#include "myStack.h"

using namespace std;

template <class T>
class myQStack : public myStack<T>
{
	myStack<T> *bottom, *top;

public:

	myQStack() : bottom(new myStack<T>()), top(new myStack<T>()) {}

	void enqueue(T d)
	{
		top->push(d);
	}

	T dequeue()
	{
		if(bottom->size == 0) {
			int tot = top->size;
			for (int i = 0; i < tot; i++)
				bottom->push(top->pop());
		}
		return bottom->pop();
	}
};

int main()
{
	myQStack<int> *s = new myQStack<int>();

	s->enqueue(1);
	s->enqueue(2);
	s->enqueue(3);

	cout << s->dequeue() << endl;
	cout << s->dequeue() << endl;
	cout << s->dequeue() << endl;

	return 0;
}