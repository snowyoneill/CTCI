#include <iostream>

#include "LinkedListT.h"

using namespace std;

template <class T>
LinkedListT<T>* partitionList(LinkedListT<T> *head, T x)
{
	LinkedListT<T> *lessThan = new LinkedListT<T>();
	LinkedListT<T> *greaterThan = new LinkedListT<T>();

	LinkedListT<T> *curr = head;
	while(curr != NULL)
	{
		if(curr->data < x)
			lessThan->appendToTail(curr->data);
		else
			greaterThan->appendToTail(curr->data);
		
		curr = curr->next;
	}
	lessThan->appendToTail(greaterThan);
	return lessThan;
}

int main()
{
	LinkedListT<int> *list = new LinkedListT<int>();
	list->appendToTail(6);
	list->appendToTail(4);
	list->appendToTail(5);
	list->appendToTail(2);
	list->appendToTail(1);

	LinkedListT<int> *ret = partitionList(list, 5);

	ret->printList();

	return 0;
}