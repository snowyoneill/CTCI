#include <iostream>

using namespace std;

#include "BinaryTree.h"

template <class T>
int getHeight(Node<T> *root) //by counting nodes.
{
	if(root == NULL)
		return 0;

	int left = getHeight(root->left) + 1;
	int right = getHeight(root->right) + 1;

	return left > right ? left : right;
}

template <class T>
int isBalanced(Node<T> *node)
{
	if(node == NULL)
		return 0;

	int left = isBalanced(node->left) + 1;
	if(left == -1)
		return -1;
	int right = isBalanced(node->right) + 1;
	if(right == -1)
		return -1;

	return (abs(left - right) > 1) ? -1 : max(left, right);
}

int main()
{
	BinaryTree<int> bTree;

	bTree.insert(5);
	bTree.insert(4);
	bTree.insert(2);
	bTree.insert(6);

	bTree.print_in_order();

	BinarySearchTree<int> bSTree;

	cout << endl;

	bSTree.insert(10);
	bSTree.insert(12);
	bSTree.insert(6);
	bSTree.insert(5);
	bSTree.insert(2);

	bSTree.print_in_order();

	print_in_order_with_levels(bSTree.root, 0);

	int h = getHeight(bSTree.root);
	cout << "Height: " << h << endl;

	int r = isBalanced(bSTree.root);
	cout << "Balanced: " << r << endl;

	return 0;
}