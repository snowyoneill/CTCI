#include <iostream>

using namespace std;

class ThreeStacks {

public:
	int *a;
	int p[3];
	int length;
	int division;

	ThreeStacks(int arr[], int l)
	{
		a = arr;
		length = l;
		division = l/3;
		
		for(int i=0; i<3; i++)
			p[i] = division * i;
	}

	void push(int stack, int d)
	{
		int max = (division*stack) + division;
		if(stack == 2 && length % 3 != 0)
			max++;

		if(p[stack] < max)
		{
			a[p[stack]] = d;
			p[stack]++;
		}
		else
			cout << "Stack: " << stack << " full - cannot push " << d << endl;
	}

	int pop(int stack)
	{
		if(p[stack] >= division*stack)
		{
			int ret;
			if(p[stack] == length)
				ret = a[p[stack]-1];
			else
				ret = a[p[stack]];
			p[stack]--;
			return ret;
		}
		else
			cout << "Stack: " << stack << " empty - cannot pop" << endl;
	}
};

int main()
{
	const int n = 10;
	int arr[n];

	ThreeStacks *newStack = new ThreeStacks(arr, n);

	newStack->push(0, 10);
	newStack->push(0, 11);
	newStack->push(0, 12);

	newStack->push(0, 13);

	newStack->push(1, 13);
	newStack->push(1, 14);
	newStack->push(1, 15);

	newStack->push(2, 16);
	newStack->push(2, 17);
	newStack->push(2, 18);
	newStack->push(2, 19);

	cout << newStack->pop(0) << endl;
	cout << newStack->pop(1) << endl;
	cout << newStack->pop(2) << endl;
	
	newStack->push(2, 20);

	return 0;
}