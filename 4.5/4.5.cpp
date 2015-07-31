#include <iostream>

using namespace std;

#include "BinaryTree.h"

template <class T>
int checkIfBST(Node<T> *node)
{
	if(node == NULL)
		return -2; // bottom of the tree

	T l = checkIfBST(node->left);
	T n = node->val;
	if(l != -2) // if your not bottom of the tree
		if(l == -1 || l > n) // check if you already returned -1 or if left is greater than the current node
			return -1;
	T r = checkIfBST(node->right);
	if(r != -2)
		if(r == -1 || r <= n)
			return -1;

	return n;
}

int last = INT_MIN;

template <class T>
bool checkIfBST2(Node<T> *node)
{
	if(node == NULL)
		return true;

	if(!checkIfBST2(node->left))
		return false;
	T n = node->val;
	if(n <= last)
		return false;
	last = n;
	if(!checkIfBST2(node->right))
		return false;

	return true;
}

template <class T>
bool checkIfBST3(Node<T> *node, T min, T max)
{
	if(node == NULL)	return true;
	
	if(node->val < min || node->val > max) return false;

	if(!checkIfBST3(node->left, min, node->val)) return false;
	if(!checkIfBST3(node->right, node->val, max)) return false;

	return true;
}

int main()
{
	BinaryTree<int> bTree;

	bTree.insert(5);
	bTree.insert(3);
	bTree.insert(6);
	bTree.insert(4);

	cout << "Is BST: " << checkIfBST(bTree.root) << endl;
	cout << "Is BST: " << checkIfBST2(bTree.root) << endl;
	cout << "Is BST: " << checkIfBST3(bTree.root, INT_MIN, INT_MAX) << endl;

	return 0;
}