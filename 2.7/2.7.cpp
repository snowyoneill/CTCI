#include <iostream>

#include "LinkedListT.h"

using namespace std;

template <class T>
bool isPalindrome(LinkedListT<T> *head, int length, LinkedListT<T> **next)
{
	if (head == NULL || length == 0)
	{
		*next = NULL;
		return true;
	}
	else if(length == 1)
	{
		*next = head->next;
		return true;
	}
	else if(length == 2)
	{
		*next = head->next->next;
		return head->data == head->next->data;
	}

	bool res = isPalindrome(head->next, length-2, next);
	if(!res || *next == NULL)
		return res;
	else
	{
		res = head->data == (*next)->data;
		*next = (*next)->next;
		return res;
	}
}

int main()
{
	LinkedListT<int> *list = new LinkedListT<int>();

	list->appendToTail(1);
	list->appendToTail(2);
	//list->appendToTail(3);
	list->appendToTail(2);
	list->appendToTail(1);

	LinkedListT<int> **nextN = new LinkedListT<int>*();
	bool res = isPalindrome(list, list->size, nextN);

	cout << res << endl;

	return 0;
}