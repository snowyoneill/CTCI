#include <iostream>

#include "myStack.h"
#include "myQueue.h"

using namespace std;

int main()
{
	myStack<int> *s = new myStack<int>();
	s->push(1);
	s->push(3);
	s->push(2);

	s->printStack();

	int ret = s->pop();
	s->pop();
	s->pop();
	ret = s->pop();

	myQueue<int> *q = new myQueue<int>();
	q->enqueue(1);
	q->enqueue(3);
	q->enqueue(2);

	q->printQueue();

	return 0;
}