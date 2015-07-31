#include <iostream>

#include "LinkedListT.h"

using namespace std;

template <class T>
LinkedListT<T>* LinkedListT<T>::removeDuplicates()
{
	LinkedListT<T> *oLL = new LinkedListT<T>();
	LinkedListT<T> *runner;

	LinkedListT<T> *curr = this;

	while(curr != NULL)
	{
		bool found = false;
		runner = oLL;
		while(runner != NULL)
		{
			if(runner->data == curr->data) {
				found = true;
				break;
			}
			
			runner = runner->next;
		}
		if(!found)
			oLL->appendToTail(curr->data);

		curr = curr->next;
	}

	return oLL;
}

template <class T>
void LinkedListT<T>::removeDuplicatesInPlace()
{
	LinkedListT<T> *curr = this;
	LinkedListT<T> *runner = curr;

	while(curr != NULL)
	{
		runner = curr;
		while(runner->next != NULL)
		{
			if(runner->next->data == curr->data)
				runner->next = runner->next->next;
			else
				runner = runner->next;
		}
		curr = curr->next;
	}
}

int main()
{
	LinkedListT<int> *newLL = new LinkedListT<int>();
	newLL->appendToTail(1);
	newLL->appendToTail(2);
	newLL->appendToTail(3);
	newLL->appendToTail(4);
	newLL->appendToTail(2);

	newLL->printList();

	cout << "Remove duplicates..." << endl;

	newLL->removeDuplicatesInPlace();
	newLL->printList();

	//LinkedListT<int> *ret = newLL->removeDuplicates();
	//ret->printList();

	return 0;
}