#include <iostream>
#include <vector>

#include "myStack.h"

using namespace std;

template <class T>
class StackOfStacks : public myStack<T>
{
public:
	vector<myStack<T>*> stacks;
	int maxStackSize;

	StackOfStacks(int s) : maxStackSize(s) {
	//StackOfStacks(int s) {
		//stacks = new vector<myStack<T>*>;
		//maxStackSize = s;

		myStack<T> *stack = new myStack<T>();
		stacks.push_back(stack);
	}

	void push(T d) {
		if(stacks[stacks.size()-1]->size < maxStackSize)
		{
			stacks[stacks.size()-1]->push(d);
		}
		else
		{
			myStack<T> *newStack = new myStack<T>(d);
			stacks.push_back(newStack);
		}
	}

	T pop() {
		if(stacks[stacks.size()-1]->size > 0)
			return stacks[stacks.size()-1]->pop();
		else
		{
			myStack<T> *stack = stacks[stacks.size()-1];
			delete stack;
			stacks.pop_back();
			pop();
		}
	}

	T peek() {
		stacks[stacks.size()-1]->top;
	}

};

int main()
{
	const int maxStackSize = 2;
	StackOfStacks<int> *sOfS = new StackOfStacks<int>(maxStackSize);

	sOfS->push(10);
	sOfS->push(11);

	sOfS->push(12);
	sOfS->push(13);

	cout << sOfS->pop() << endl;
	cout << sOfS->pop() << endl;

	cout << sOfS->pop() << endl;

	return 0;
}