#include <iostream>
#include "BinaryTree.h"

template <class T>
bool treesMatch(Node<T> *n1, Node<T> *n2)
{
	if(n1 == NULL && n2 == NULL) return true;

	/*
	 * if((n1 == NULL && n2 != NULL) || (n1 != NULL && n2 == NULL))
	 * unnecessary as we have already checked above if the 2 nodes are equal.
	 */																
	if(n1 == NULL || n2 == NULL)
		return false;

	if(n1->val != n2->val) return false;

	return treesMatch(n1->left, n2->left) && treesMatch(n1->right, n2->right);
}

template <class T>
bool isSubTree(Node<T> *T1, Node<T> *T2)
{
	if(T1 == NULL) return true;

	if(T1->val == T2->val)
		return treesMatch(T1, T2);

	return isSubTree(T1->left, T2) || isSubTree(T1->right, T2);
}

int main()
{
	{
		Node<int> bTree1(1), bTree2(1);

		bTree1.left = new Node<int>(2);
		bTree1.right = new Node<int>(3);

		bTree2.left = new Node<int>(2);
		bTree2.right = new Node<int>(3);
		bTree2.left->left = new Node<int>(4);

		std::cout << treesMatch(&bTree1, &bTree2) << std::endl;
	}

	//------------------------------------------------------

	{
		Node<int> bTree1(2), bTree2(1);

		bTree1.left = new Node<int>(1);
		bTree1.right = new Node<int>(10);

		bTree1.left->left = new Node<int>(2);
		bTree1.left->right = new Node<int>(3);

		bTree2.left = new Node<int>(2);
		bTree2.right = new Node<int>(3);

		std::cout << isSubTree(&bTree1, &bTree2) << std::endl;
	}

	return 0;
}