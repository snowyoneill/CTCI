#include <iostream>

int countBitChanges(int a, int b)
{
	int count=0;
	for(int i = a ^ b; i != 0; i >>= 1)
		if(i & 1) count++;

	return count;
}

int countBitChanges2(int a, int b)
{
	int count=0;
	for(int i = a ^ b; i != 0; i = i & (i-1))
		count++;

	return count;
}

int main()
{
	int a = 7;//31;
	int b = 8;//14;

	int res = countBitChanges(a, b);
	int res2 = countBitChanges2(a, b);

	std::cout << res << std::endl;
	std::cout << res2 << std::endl;
	
	return 0;
}