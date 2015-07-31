#include <iostream>

int main()
{
	int x = 16;

	// flip the least significant bit with x & (x-1)
	// if only one bit is set then it must be a power of 2
	if( (x & (x-1)) == 0)
		std::cout << "Power of 2" << std::endl;
	else
		std::cout << "Not a power of 2" << std::endl;

	return 0;
}