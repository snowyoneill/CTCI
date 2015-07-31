#include <iostream>

#include "LinkedListT.h"

using namespace std;

template <class T>
bool LinkedListT<T>::deleteInPlace(LinkedListT<T> *node)
{
	if(node == NULL || node->next == NULL)
		return false;

	LinkedListT<T> *nextN = node->next;
	node->data = nextN->data;
	node->next = nextN->next;

	delete nextN;
	return true;
}

int main()
{
	LinkedListT<int> *newL = new LinkedListT<int>(1);
	newL->appendToTail(2);

	LinkedListT<int> *node = new LinkedListT<int>(3);
	newL->appendToTail(node);

	newL->appendToTail(4);

	newL->printList();
	cout << "---" << endl;

	newL->deleteInPlace(node);
	
	newL->printList();
	cout << "---" << endl;

	return 0;
}