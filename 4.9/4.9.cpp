#include <iostream>
#include "BinaryTree.h"

template <class T>
void printPath(T a[], int start, int level)
{
	for(int i=start; i<=level; i++)
		std::cout << a[i] << ", ";

	std::cout << std::endl;
}

template <class T>
void sumPaths(Node<T> *node, T a[], T sum, int level)
{
	if(node == NULL) return;

	a[level] = node->val;

	T checkSum = T();
	for(int i=level; i>=0; i--)
	{
		checkSum += a[i];
		if(checkSum == sum)
			printPath(a, i, level);
	}

	sumPaths(node->left, a, sum, level+1);
	sumPaths(node->right, a, sum, level+1);

	a[level] = INT_MIN;
}

int main()
{
	Node<int> root(3);

	root.left = new Node<int>(3);
	root.right = new Node<int>(2);

	root.left->left = new Node<int>(1);
	root.left->right = new Node<int>(2);
	root.left->right->left = new Node<int>(1);

	root.right->right = new Node<int>(10);
	root.right->left = new Node<int>(4);
	root.right->left->left = new Node<int>(1);
	root.right->left->left->left = new Node<int>(-1);

	print_in_order_with_levels(&root, 0);

	const int DEPTH = 4;
	int a[DEPTH];
	int sum = 6;
	sumPaths(&root, a, sum, 0);

	return 0;
}