#include <iostream>
#include <vector>

#include "LinkedListT.h"
#include "BinaryTree.h"

using namespace std;

/*
 * From last attempt - no idea why i decided to go with a vector of vectors.
 *
std::vector<std::vector<LinkedListT<int>>> lists;

void createLevelLL(Node<int> *head, int level)
//vector<LinkedListT> createLevelLL(BinaryTree* head, int level)
{
	if(head == NULL)
		return;

	LinkedListT<int>* curr = new LinkedListT<int>(head->val);

	std::vector<LinkedListT<int>> row;
	row.push_back(*curr);

	if(!lists.empty() && level < (int)lists.size())
		lists[level].push_back(*curr);
	else
		lists.push_back(row);

	createLevelLL(head->left, level + 1);
	createLevelLL(head->right, level + 1);
	
}

int main()
{
	BinaryTree<int>* input = new BinaryTree<int>(3);
	input->insert(2);
	//input->add(1);
	input->insert(4);

	input->print_in_order();

	printf("\n");

	//lists = std::vector<std::vector<LinkedListT<int>>>();

	createLevelLL(input->root, 0);

	return 0;
}
 */

//template <class T>
//vector<LinkedListT<T>*> depthL;

vector<LinkedListT<int>*> depthL;

template <class T>
void depthList(Node<T> *node, int level)
{
	if(node == NULL)
		return;

	LinkedListT<T> *ll = new LinkedListT<T>(node->val);

	if((int)depthL.size() <= level)
		depthL.push_back(ll);
	else
		depthL[level]->appendToTail(ll);

	depthList(node->left, level+1);
	depthList(node->right, level+1);
}

int main()
{
	BinarySearchTree<int> bSTree;

	//bSTree.insert(2);
	//bSTree.insert(1);
	//bSTree.insert(3);

	bSTree.insert(10);
	bSTree.insert(12);
	bSTree.insert(6);
	bSTree.insert(5);
	bSTree.insert(2);

	depthList(bSTree.root, 0);

	for(int i=0; i<(int)depthL.size(); i++)
	{
		cout << "Level " << i << ": ";
		depthL[i]->printList();
		cout << endl;
	}

	return 0;
}