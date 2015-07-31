#include <iostream>

int countBitsSet(int x)
{
	int count = 0;
	for(int i = x; i != 0; i = i & (i-1))
		count++;
	return count;
}

int nextGreater(int x)
{
	int bits = countBitsSet(x);

	while(true)
	{
		x += 1;
		int r = countBitsSet(x);
		if(r == bits)
			return x;
	}

	return -1;
}

int nextLower(int x)
{
	int bits = countBitsSet(x);

	while(x > 0)
	{
		x -= 1;
		int r = countBitsSet(x);
		if(r == bits)
			return x;
	}

	return -1;
}

int main()
{
	int x = 12;

	int nextG = nextGreater(x);
	int nextL = nextLower(x);

	std::cout << "No: " << x << " next greater: " << nextG \
		<< " next lower: " << nextL << std::endl;

	return 0;
}