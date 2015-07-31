#include "LinkedListT.h"

template <class T>
class myQueue {

	public:
		LinkedListT<T> *front, *back;
		int size;

		myQueue() : front(NULL), back(NULL), size(0) {}
		~myQueue() {}

		void enqueue(T d) {
			LinkedListT<T> *item = new LinkedListT<T>(d);
			if(size == 0) {
				front = back = item;
			}
			else {
				back->next = item;
				back = item;
			}
			size++;
		}

		T peek()
		{
			if(front)
				return front->data;
		}

		T dequeue() {
			if(size > 0) {
				LinkedListT<T> *item = front;
				front = front->next;
				size--;
				return item->data;
			}
			return NULL;
		}

		void printQueue(void) {
			LinkedListT<T> *it = front;
			while(it != NULL) {
				cout << it->data << ", ";
				it = it->next;
			}
		}
};