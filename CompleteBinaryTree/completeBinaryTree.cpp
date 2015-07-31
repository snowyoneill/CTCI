#include "CompleteBinaryTree.h"

using namespace std;

int main()
{
	CompleteBinaryTree<int> tree;

	tree.insert(10);
	tree.insert(11);
	tree.insert(12);
	tree.insert(8);
	tree.insert(9);
	tree.insert(7);

	print_in_order_with_levels(tree.root, 0);

	return 0;
}