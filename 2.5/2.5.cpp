#include <iostream>
#include <cmath>

#include "LinkedListT.h"

using namespace std;

template <class T>
LinkedListT<T>* sumLL(LinkedListT<T> *l1, LinkedListT<T> *l2)
{
	LinkedListT<T> *sumL = new LinkedListT<T>();

	int carry = 0;
	while(l1 != NULL || l2 != NULL)
	{
		int no1, no2;
		no1 = no2 = 0;

		if(l1 != NULL)
		{
			no1 = l1->data;
			l1 = l1->next;
		}

		if(l2 != NULL)
		{
			no2 = l2->data;
			l2 = l2->next;
		}

		int sum = no1 + no2 + carry;
		carry = sum / 10;
		
		sumL->appendToTail(sum % 10);
	}
	if(carry)
		sumL->appendToTail(carry);

	return sumL;
}

template <class T>
LinkedListT<T>* sumLLForward(LinkedListT<T> *l1, LinkedListT<T> *l2)
{
	LinkedListT<T> *sumLL = new LinkedListT<T>();

	int l1Size = l1->size;
	int l2Size = l2->size;

	int no1 = 0, no2 = 0;
	int count = l1Size-1;
	for (int i = 0; i < l1Size; i++)
	{
		no1 += l1->data * pow(10.0f, count);
		l1 = l1->next;
		count--;
	}

	count = l2Size-1;
	for (int i = 0; i < l2Size; i++)
	{
		no2 += l2->data * pow(10.0f, count);
		l2 = l2->next;
		count--;
	}

	int sum = no1 + no2;

	int base = log10((double)sum);
	int topPower = pow(10.0f, base);

	sumLL->appendToTail(sum / topPower);
	int rem = sum % topPower;
	topPower /= 10;
	
	while(rem != 0)
	{
		sumLL->appendToTail(rem / topPower);
		rem = sum % topPower;
		topPower /= 10;
	}

	return sumLL;
}

template <class T>
LinkedListT<T>* sumLLRecursive(LinkedListT<T> *node1, LinkedListT<T> *node2, int carry)
{
	cout << "Original sum LL recursive" << endl;
}

template <>
LinkedListT<int>* sumLLRecursive(LinkedListT<int> *node1, LinkedListT<int> *node2, int carry)
{
	if(node1 == NULL && node2 == NULL && carry == 0)
		return NULL;

	int sum = 0;
	if(node1)
		sum += node1->data;
	if(node2)
		sum += node2->data;

	sum += carry;

	int rem = sum % 10;
	LinkedListT<int> *r = new LinkedListT<int>(rem);
	carry = sum / 10;

	node1 = (node1 == NULL) ? NULL : node1->next;
	node2 = (node2 == NULL) ? NULL : node2->next;
	LinkedListT<int> *rec = sumLLRecursive(node1, node2, carry);
	r->appendToTail(rec);

	return r;
}

template <class T>
LinkedListT<T>* sumLLRecursiveF(LinkedListT<T> *node1, LinkedListT<T> *node2, int *carry)
{
	cout << "Original sum LL recursive forward" << endl;
}

template <> //Doesnt work when lists are different lengths
LinkedListT<int>* sumLLRecursiveF(LinkedListT<int> *node1, LinkedListT<int> *node2, int *carry)
{
	if(node1 == NULL && node2 == NULL && *carry == 0)
		return NULL;

	LinkedListT<int> *r = sumLLRecursiveF((node1 == NULL) ? NULL : node1->next, (node2 == NULL) ? NULL : node2->next, carry);

	int sum = 0;
	if(node1)
		sum += node1->data;
	if(node2)
		sum += node2->data;

	sum += *carry;

	int rem = sum % 10;
	*carry = sum / 10;
	LinkedListT<int> *sumL = new LinkedListT<int>(rem);
	sumL->appendToTail(r);

	return sumL;
}

LinkedListT<int>* sumLLRecursiveFHelper(LinkedListT<int> *l1, LinkedListT<int> *l2)
{
	/* Pad shorter Linked list with zeros for recursion
	 */
	int diff = l1->size - l2->size;
	if(diff != 0)
	{
		LinkedListT<int> *pad = new LinkedListT<int>();
		for (int i = 0; i < abs(diff); i++)
			pad->appendToTail(0);

		if(diff < 0) {
			pad->appendToTail(l1);
			l1 = pad;
		}
		else {
			pad->appendToTail(l2);
			l2 = pad;
		}
	}

	int *carry = new int(0);
	LinkedListT<int> *sum = sumLLRecursiveF(l1, l2, carry);
	if(*carry != 0)
	{
		LinkedListT<int> *r = new LinkedListT<int>(*carry);
		r->appendToTail(sum);
		sum = r;
	}
	return sum;
}

int main()
{
	/*
Input: (7-> 1 -> 6) + (5 -> 9 -> 2).That is, 617 + 295.
Output: 2 -> 1 -> 9.That is, 912
	*/

	/*

	LinkedListT<int> *l1 = new LinkedListT<int>();
	l1->appendToTail(0);
	l1->appendToTail(5);
	//l1->appendToTail(6);

	LinkedListT<int> *l2 = new LinkedListT<int>();
	l2->appendToTail(0);
	l2->appendToTail(5);
	l2->appendToTail(9);

	//LinkedListT<int> *sum = sumLL(l1, l2);

	LinkedListT<int> *sum = sumLLRecursive(l1, l2, 0);

	*/

	/*
FOLLOW UP
Suppose the digits are stored in forward order. Repeat the above problem.
EXAMPLE
Input: (6 -> 1 -> 7) + (2 -> 9 -> 5).That is, 617 + 295.
Output: 9 -> 1 -> 2.That is, 912.
	*/

	LinkedListT<int> *l1 = new LinkedListT<int>();
	//l1->appendToTail(0);
	l1->appendToTail(5);
	//l1->appendToTail(6);

	LinkedListT<int> *l2 = new LinkedListT<int>();
	l2->appendToTail(9);
	l2->appendToTail(5);
	//l2->appendToTail(5);
	//l2->appendToTail(1);

	//LinkedListT<int> *sum = sumLLForward(l1, l2);

	// ---------- Recursion ---------- //

	LinkedListT<int> *sum = sumLLRecursiveFHelper(l1, l2);

	sum->printList();

	return 0;
}