#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include "binary_tree.h"

namespace algo
{
	template<typename T>
	class BinarySearchTree : public BinaryTree<T>
	{
	public:
		void add(const T& data);

	};
}

#endif
