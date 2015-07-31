#include <iostream>

#include "LinkedListT.h"

using namespace std;

template <class T>
LinkedListT<T>* findCycle(LinkedListT<T>* head)
{
	LinkedListT<T> *curr = head;
	LinkedListT<T> *runner = head;

	while(runner != NULL && runner->next != NULL)
	{
		curr = curr->next;
		runner = runner->next->next;
		if(curr == runner)
			break;
	}

	if(runner == NULL || runner->next == NULL)
		return NULL;

	curr = head;
	while(runner != curr)
	{
		curr = curr->next;
		runner = runner->next;
	}

	return curr;
}

int main()
{
	LinkedListT<int> *list = new LinkedListT<int>();
	list->appendToTail(1);
	list->appendToTail(2);

	LinkedListT<int> *loopHead = new LinkedListT<int>(3);
	list->appendToTail(loopHead);

	list->appendToTail(4);
	list->appendToTail(5);
	list->appendToTail(6);
	list->appendToTail(loopHead);

	LinkedListT<int> *ret = findCycle(list);

	if(ret)
		cout << ret->data << endl;
	else
		cout << "No cycle found." << endl;

	return 0;
}