#include <iostream>
#include <cmath>

#define SetBit(A, k) (A |= (1 << k))
#define CheckBit(A, k) (A & (1 << k))
#define log2(x) (log10((double)x) / log10((double)2))

/* Creates a bit array represented by the input number - where an long long number is treated as a sequence of characters. 
 */
int createBitArray(long long input)
{
	int k = 0;
	int count = 0;
	while(input > 0)
	{
		int idx = input % 10;
		if(idx)
			SetBit(k, count);
		input /= 10;
		count++;
	}
	return k;
}

/* Prints bit representation of number in left to right form.
 */
void printBitArray(long long input)
{
	int c = log2(input);
	int topPower = pow(2.0f, c);

	int rem = input;
	while(topPower != 0)
	{
		std::cout << rem / topPower;
		rem = rem % topPower;
		topPower /= 2;
	}
}

long long insertMInN(int n, int m, int i, int j)
{
#if 0
	int mask = ~((1 << j + 1)-1); // set all bits left of j
	mask |= ((m << i) | ((1 << i)-1)); // merge mask with pattern M shifted to position j
									   // with 1's to right of i.

	int t = (1 << j+1)-1; //all 1's from j through to 0
	int s = ~((1 << i)-1) ;//   0's from i through to 0
	t &= s;

	n |= t; // set all bits from j through to i in n

	long long res = n & mask; // AND mask and modified n together.
#endif

#if 1
	int mask = ~0; //set all bits to 1
	mask <<= j+1; //shift all 1's j+1 places left
	mask |= ((1 << i)-1); //set all bits right of i to 1
	
	long long res = n & mask;//AND mask and original n bit array - this will clear the positions j through to i
	res |= (m << i);//shift the replacement bits to the correct position and logically OR them.
#endif

	return res;
}

int main()
{
	long long N = 11111111111; //long long - 64 bits - max 21 digit sequence.
	long long M = 10011;
	int i = 2, j = 6;

	int n = createBitArray(N);
	int m = createBitArray(M);

	std::cout << "N: ";
	printBitArray(n);
	std::cout << std::endl;
	std::cout << "M: ";
	printBitArray(m);
	std::cout << std::endl;

	long long res = insertMInN(n, m, i, j);

	std::cout << "R: ";
	printBitArray(res);
	std::cout << std::endl;

	return 0;
}