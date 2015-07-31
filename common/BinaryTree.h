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
class BinaryTree
{
public:
	Node<T> *root;
	int size;

	BinaryTree() : root(NULL), size(0) {}
	BinaryTree(T d) : root(new Node<T>(d)), size(1) {}

	//void insert(Node<T> **node, T d) {
	//	(*node)->val = d;
	//}

	void insert(Node<T> *&node, T d) {
		if(node == NULL)
			node = new Node<T>(d);
		else
		{
			if(node->left == NULL)
				node->left = new Node<T>(d);
			else if(node->right == NULL)
				node->right = new Node<T>(d);
			else
			{
				insert(node->left, d); // Maybe check the height of both the left and right
									   // nodes before deciding which branch to append to
									   // to help balance the tree. However this would be very expensive.
			}
		}
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

template <class T>
class BinarySearchTree : public BinaryTree<T>
{
public:
	void insert(Node<T> *&root, T d)
	{
		if(root == NULL)
			root = new Node<T>(d);
		else
		{
			if(d <= root->val)
				insert(root->left, (d));
			else
				insert(root->right, (d));
		}
	}

	void insert(T d)
	{
		insert(this->root, d);
	}
};

/*
 * Template binary tree with node class encapsulated 
 *
template <class T>
class BinaryTree
{
protected:
	struct Node
	{
		Node *left, *right;
		T val;

		Node(T d)
			: left(NULL)
			, right(NULL)
			, val(d)
		{}
	};

public:
	Node *root;
	int size;

	BinaryTree() : root(NULL), size(0) {}
	BinaryTree(T d) : root(new Node(d)), size(1) {}

	~BinaryTree() {}

	void insert(T d) { 
		if(root == NULL)
			root = new Node(d);
		else
		{
			if(root->left == NULL)
				root->left = new Node(d);
			else
				root->right = new Node(d);
		}
	}

	void print_in_order(Node *root)
	{
		if(root != NULL)
		{
			print_in_order(root->left);
			cout << root->val << ", ";
			print_in_order(root->right);
		}
	}

	void print_in_order()
	{
		print_in_order(this->root);
	}
};

template <class T>
class BinarySearchTree : public BinaryTree<T>
{
public:
	void insert(T d)
	{
		if(root == NULL)
			root = new Node(d);
		else
		{
			if(d <= root->val)
				root->left = new Node(d);
			else
				root->right = new Node(d);
		}
	}
};

*/

#include<iomanip>
template <class T>
void print_in_order_with_levels(Node<T> *node, int level)
{
	if(node != NULL)
	{
		print_in_order_with_levels(node->left, level+1);
		std::cout << std::setw(level*5) << node->val << std::endl;
		print_in_order_with_levels(node->right, level+1);
	}
}

//template <>
//void print_in_order_with_levels<int>(Node<int> *node, int level);