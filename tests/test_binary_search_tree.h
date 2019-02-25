#ifndef TEST_BINARY_SEARCH_TREE_H
#define TEST_BINARY_SEARCH_TREE_H


#include "..\struct\tree\binary_search_tree.h"
#include "tester.h"

namespace algo
{
	void test_binary_search_tree()
	{
		BinarySearchTree<int> bst;
		int a[] = { 0, 3, 2, 5, 4, 6, 9, 8, 7, 1 };
		for (int i = 0; i < 10; ++i)
		{
			bst.add(a[i]);
		}
		bst.showSorted();
	}
	
}



#endif
