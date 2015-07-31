#include <iostream>

#include "LinkedListT.h"

using namespace std;

template <class T>
LinkedListT<T>* LinkedListT<T>::kLastElement2(LinkedListT<T> *head, int k, int *i)
{
	if(head == NULL)
		return NULL;
	

	LinkedListT<T> *ret = kLastElement2(head->next, k, i);
	*i = *i + 1;
	if(*i == k)
	{
		return head;
	}

	return ret;
}

template <class T>
LinkedListT<T>* LinkedListT<T>::kLastElement2(int k, int *i)
{
	if(this == NULL)
		return NULL;
	

	LinkedListT<T> *ret = this->next->kLastElement2(k, i);
	*i = *i + 1;
	if(*i == k)
	{
		return this;
	}

	return ret;
}

template <class T>
LinkedListT<T>* LinkedListT<T>::kLastElement(int k)
{
	LinkedListT<T> *curr = this;
	LinkedListT<T> *runner = this;

	int count = 0;
	while(runner->next != NULL && count < k) {
		runner = runner->next;
		count++;
	}
	if(count + 1 < k)
		return runner;

	while(runner->next != NULL)
	{
		runner = runner->next;
		curr = curr->next;
	}
	return curr;
}

int main()
{

	LinkedListT<int> *list = new LinkedListT<int>(1);
	list->appendToTail(2);
	list->appendToTail(3);

	//LinkedListT<int> *ret = list->kLastElement(3);
	int *count = new int(0);

	LinkedListT<int> *ret = list->kLastElement2(3, count);

	cout << ret->data << endl;

	return 0;
}