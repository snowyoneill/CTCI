#include <iostream>
#include <limits>

//http://www.cplusplus.com/doc/tutorial/exceptions/
//http://stackoverflow.com/questions/4798578/c-templates-problem-convert-to-null

using namespace std;

#include "myStack.h"

template <class T>
class myStackWithMin : public myStack<T>
{
public:
	T minV;
	myStack *minS;

	myStackWithMin() : minS(new myStack<T>()), minV(numeric_limits<T>::max()) {}

	void push(T d)
	{
		if(d < minV)
		{
			minV = d;
			minS->push(d);
		}
		myStack<T>::push(d);
	}

	T pop()
	{
		T ret = myStack<T>::pop();
		if(ret == min())
			minS->pop();

		return ret;
	}

	T min()
	{
		if(minS->top == NULL)
			throw std::logic_error( "stack is empty" );
		
		return minS->top->data;		
	}

};

int main()
{
	myStackWithMin<int> *newMinStack = new myStackWithMin<int>();
	newMinStack->push(10);
	newMinStack->push(5);
	newMinStack->push(2);
	
	newMinStack->printStack();

	cout << newMinStack->min() << endl;

	newMinStack->pop();

	cout << newMinStack->min() << endl;

	newMinStack->pop();

	cout << newMinStack->min() << endl;

	newMinStack->pop();
	//newMinStack->pop();

	cout << newMinStack->min() << endl;

	return 0;
}