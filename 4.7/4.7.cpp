#include <iostream>

using namespace std;

#include "BinaryTree.h"

/* Returns true if p is a descendent of root */
template <class T>
bool covers(Node<T> *root, T p) {
	if (root == NULL) return false;
	if (root->val == p) return true;
	return covers(root->left, p) || covers(root->right, p);
}

template <class T>
Node<T>* commonAncestorHelper(Node<T> *root, T p, T q) {
	  if (root == NULL) return NULL;
	  if (root->val == p || root->val == q) return root;

	  bool is_p_on_left = covers(root->left, p);
	  bool is_q_on_left = covers(root->left, q);

	  /* If p and q are on different sides, return root. */
	  if (is_p_on_left != is_q_on_left) return root;

	  /* Else, they are on the same side. Traverse this side. */
	  Node<T>* child_side = is_p_on_left ? root->left : root->right;
	  return commonAncestorHelper(child_side, p, q);
}

template <class T>
Node<T>* commonAncestor(Node<T> *root, T p, T q) {
	if (!covers(root, p) || !covers(root, q)) { // Error check
		return NULL;
	}
	return commonAncestorHelper(root, p, q);
}

bool found1 = false;
bool found2 = false;

template <class T>
Node<T>* commonAncestor2(Node<T> *node, T x, T y)
{
	if(node == NULL) return NULL;

	Node<T> *l = commonAncestor2(node->left, x, y);
	if(found1 && found2 && l != NULL) return l;

	if(node->val == x) found1 = true;
	if(node->val == y) found2 = true;

	if(found1 && found2)
		return NULL;

	Node<T> *r = commonAncestor2(node->right, x, y);
	if(found1 && found2 && r != NULL)
		return r;

	if(found1 && found2) return node;

	return NULL;
}

int main()
{
	BinaryTree<int> bTree;

	Node<int> root(6);
	Node<int> l(5);
	Node<int> ll(2);
	Node<int> lll(1);
	Node<int> llr(4);
	Node<int> llrl(3);
	Node<int> lr(8);
	Node<int> lrr(11);

	BinarySearchTree<int> bSTree;

	//bSTree.insert(6);
	//bSTree.insert(5);
	//bSTree.insert(2);
	//bSTree.insert(1);
	//bSTree.insert(4);
	//bSTree.insert(3);

	bSTree.insert(5);
	bSTree.insert(3);
	bSTree.insert(8);
	bSTree.insert(2);
	bSTree.insert(4);
	bSTree.insert(1);
	bSTree.insert(7);
	bSTree.insert(11);

	bSTree.print_in_order();

	Node<int> *res = commonAncestor<int>(bSTree.root, 7, 11);
	if(res)
		cout << "Common Ancestor: " << res->val << endl;
	else
		cout << "Common Ancestor: NULL" << endl;

	/* Returns 5 instead of 8 - ****wrong answer.****
	 */
	Node<int> *res1 = commonAncestor2<int>(bSTree.root, 7, 11);
	if(res1)
		cout << "Common Ancestor: " << res1->val << endl;
	else
		cout << "Common Ancestor: NULL" << endl;

	return 0;
}