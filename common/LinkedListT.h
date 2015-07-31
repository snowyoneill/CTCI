#pragma once

#include <iostream>

template <class T>
class LinkedListT {

	public:

		LinkedListT *next;
		T data;
		int size;

		LinkedListT() : next(NULL), data(), size(0) {}
		LinkedListT(T d) : next(NULL), data(d), size(1) {}
		~LinkedListT() {}

		void appendToTail(T d) {
			LinkedListT *start = this;
			if(size == 0) { // used to overwrite the head of the linked list with a node containing data.
				start->data = d;
				size++;
				return;
			}

			LinkedListT<T> *curr = new LinkedListT(d);
			while(start->next != NULL)
				start = start->next;
			start->next = curr;
			size++;
		}
		void appendToTail(LinkedListT<T> *node);

		void printList() {
			LinkedListT *curr = this;

			while(curr != NULL) {
				cout << curr->data << ", ";
				curr = curr->next;
			}
		}

		LinkedListT<T>* removeDuplicates();
        void removeDuplicatesInPlace();

		//2.2
		LinkedListT<T>* kLastElement(int k);
		LinkedListT<T>* kLastElement2(LinkedListT<T> *head, int k, int *i);
		LinkedListT<T>* kLastElement2(int k, int *i);

		//2.3
        bool deleteInPlace(LinkedListT<T> *node);
};

template <class T>
void LinkedListT<T>::appendToTail(LinkedListT<T> *node)
{
	LinkedListT *start = this;
	if(size == 0) { // used to overwrite the head of the linked list with a node containing data.
		start = node;
		size++;
		return;
	}

	LinkedListT<T> *curr = node;
	while(start->next != NULL)
		start = start->next;
	start->next = curr;
}