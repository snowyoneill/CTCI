#include "LinkedListT.h"

template <class T>
class myStack {
	public:
		LinkedListT<T> *top;
		int size;

		myStack() : top(NULL), size(0) {};
		myStack(T d) : top(new LinkedListT<T>(d)), size(1) {};
		~myStack() {}

		void push(T d) {
			LinkedListT<T> *item = new LinkedListT<T>(d);
			if(size == 0)
				top = item;
			else
			{
				item->next = top;
				top = item;
			}
			size++;
		}

		T peek()
		{
			return top->data;
		}

		T pop(void) {
			//if(size > 0 && top != NULL)
			if(size > 0)
			{
				T data = top->data;
				top = top->next;

				size--;

				return data;
			}
			throw std::logic_error( "stack is empty" );
			//return T();
		}

		void printStack()
		{
			LinkedListT<T> *it = top;
			while(it != NULL)
			{
				std::cout << it->data << ", ";
				it = it->next;
			}
			std::cout << std::endl;
		}
};