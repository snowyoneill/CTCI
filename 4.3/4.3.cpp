#include <iostream>

#include "BinaryTree.h"

using namespace std;

template <class T>
Node<T>* buildMinBST(int a[], int start, int end)
{
	if(start > end) return NULL;

	int mid = (start + end) / 2;
	Node<T>* node = new Node<T>(a[mid]);
	node->left = buildMinBST<T>(a, start, mid-1);
	node->right = buildMinBST<T>(a, mid+1, end);

	return node;
}

int main()
{
	int a[] = {1,2,3,4,5,6,7,8,9,10};

	Node<int> *minBST = buildMinBST<int>(a, 0, 9);

	BinaryTree<int> bST;
	bST.root = minBST;
	
	bST.print_in_order();

	return 0;
}