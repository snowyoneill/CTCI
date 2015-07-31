#include <iostream>

using namespace std;

#include "BinaryTree.h"

template <class T>
class NodeWithParent
{
public:
	NodeWithParent<T> *left, *right, *parent;
	T val;

	NodeWithParent(T d)
		: left(NULL)
		, right(NULL)
		, parent(NULL)
		, val(d)
	{}
};

template <class T>
void print_in_order_with_levels(NodeWithParent<T> *node, int level)
{
	if(node != NULL)
	{
		print_in_order_with_levels(node->left, level+1);
		cout << setw(level*5) << node->val << endl;
		print_in_order_with_levels(node->right, level+1);
	}
}

template <class T>
NodeWithParent<T>* leftMostChild(NodeWithParent<T>* n) {
	if (n == NULL) return NULL;

	while (n->left != NULL)
		n = n->left;

	return n;
}

template <class T>
NodeWithParent<T>* inorderSucc(NodeWithParent<T>* n) {
	if (n == NULL) return NULL;

	/* Found right children -> return leftmost node of right
	* subtree. */
	if (n->right != NULL) {
		return leftMostChild(n->right);
	} else {
		NodeWithParent<T>* q = n;
		NodeWithParent<T>* x = q->parent;
		// Go up until we're on left instead of right
		while (x != NULL && x->left != q) {
			q = x;
			x = x->parent;
		}
	return x;
	}
}

bool found = false;
template <class T>
Node<T>* nextNodeInOrder(Node<T> *node, T x)
{
	if(node == NULL) return NULL;

	Node<T> *l = nextNodeInOrder(node->left, x);
	if(found && l != NULL) return l;

	if(node->val == x)
	{
		found = true;
		return NULL;
	}

	if(found)
		return node;

	Node<T> *r = nextNodeInOrder(node->right, x);
	if(found && r != NULL) return r;

	return NULL;
}

int main()
{
	BinarySearchTree<int> bSTree;

	bSTree.insert(6);
	bSTree.insert(5);
	bSTree.insert(2);
	bSTree.insert(1);
	bSTree.insert(4);
	bSTree.insert(3);

	bSTree.print_in_order();
	print_in_order_with_levels(bSTree.root, 0);

	Node<int> *res = nextNodeInOrder<int>(bSTree.root, 3);
	if(res)
		printf("Found: %d\n", res->val);
	else
		printf("Found: null\n");

	//---------------------------------------------------

	std::cout << std::endl;

	NodeWithParent<int> nP(1);

	nP.left = new NodeWithParent<int>(2);
	nP.right = new NodeWithParent<int>(3);
	nP.left->parent = &nP;
	nP.right->parent = &nP;

	nP.left->left = new NodeWithParent<int>(4);
	nP.left->right = new NodeWithParent<int>(5);
	nP.left->left->parent = nP.left;
	nP.left->right->parent = nP.right;

	print_in_order_with_levels(&nP, 0);

	NodeWithParent<int> *res2 = inorderSucc<int>(nP.left);
	if(res2)
		printf("Found: %d\n", res2->val);
	else
		printf("Found: null\n");

	return 0;
}