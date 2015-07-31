//http://www.geeksforgeeks.org/linked-complete-binary-tree-its-creation/

#include "myQueue.h"

/*
 * Template node class and binary tree
 */
template <class T>
class Node
{
public:
	Node<T> *left, *right;
	T val;

	Node(T d)
		: left(NULL)
		, right(NULL)
		, val(d)
	{}
};

template <class T>
class CompleteBinaryTree
{
public:
	Node<T> *root;
	int size;
	myQueue<Node<T>*> *q;

	CompleteBinaryTree() : root(NULL), size(0), q(new myQueue<Node<T>*>()) {}
	CompleteBinaryTree(T d) : root(new Node<T>(d)), size(1), q(new myQueue<Node<T>>()) { q->enqueue(root); }

	//void insert(Node<T> **node, T d) {
	//	(*node)->val = d;
	//}

	void insert(Node<T> *&node, T d) {

		Node<T> *n = new Node<T>(d);

		if(node == NULL)
			node = n;
		else
		{
			Node<T> *front = q->peek();

			if(front->left == NULL)
				front->left = n;
			else if(front->right == NULL)
				front->right = n;
			
			if(front->left != NULL && front->right != NULL)
				q->dequeue();
		}
		q->enqueue(n);
	}

	void insert(T d) { 
		insert(this->root, d);
	}

	void print_in_order(Node<T> *node)
	{
		if(node != NULL)
		{
			print_in_order(node->left);
			cout << node->val << ", ";
			print_in_order(node->right);
		}
	}

	void print_in_order()
	{
		print_in_order(this->root);
		cout << endl;
	}
};

#include<iomanip>
template <class T>
void print_in_order_with_levels(Node<T> *node, int level)
{
	if(node != NULL)
	{
		print_in_order_with_levels(node->left, level+1);
		cout << setw(level*5) << node->val << endl;
		print_in_order_with_levels(node->right, level+1);
	}
}
