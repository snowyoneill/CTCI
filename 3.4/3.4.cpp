#include <iostream>
#include "myStack.h"

template <typename T>
void moveDisk(T fp, T tp)
{
	std::cout << "moving disk from "  << fp << " to " << tp << std::endl;
}

//template <typename T >
//void moveDisk<int>(T fp, T tp)
//void moveDisk<myStack<int>>(myStack<int> fp, myStack<int> tp)
//{
//	std::cout << "moving disk from "  << fp.peek() << " to " << tp..peek() << std::endl;
//}

template <typename T>
void moveTower(int height, T origin, T destination, T buffer)
//void moveTower(int height, int origin, int destination, int buffer)
{
	if(height <= 0) return;
    //if(height >= 1)
	//{
        moveTower(height-1, origin, buffer, destination);
        moveDisk(origin, destination);
        moveTower(height-1, buffer, destination, origin);
	//}
}

template <typename T>
void moveTowerStack(int height, T &origin, T &destination, T &buffer, int a, int b, int c)
{
	if(height <= 0) return;

	moveTowerStack<myStack<int>>(height-1, origin, buffer, destination, a, c, b);

	destination.push(origin.pop());
	//moveDisk<myStack<int>>(a, b); // OR moveDisk(a, b);
	moveDisk(a, b);

	moveTowerStack<myStack<int>>(height-1, buffer, destination, origin, c, b, a);
}

int main()
{
	moveTower(3, "A", "B", "C");
	//moveTower(3, 1, 2, 3);

	//---- using custom myStack class ----

	std::cout << std::endl;

	myStack<int> origin, desintation, buffer;
	
	origin.push(3);
	origin.push(2);
	origin.push(1);

	std::cout << "Origin stack: ";
	origin.printStack();
	std::cout << "Desintation stack: ";
	desintation.printStack();

	moveTowerStack(origin.size, origin, desintation, buffer, 1, 2, 3);

	std::cout << "Origin stack: ";
	origin.printStack();
	std::cout << "Desintation stack: ";
	desintation.printStack();

	return 0;
}