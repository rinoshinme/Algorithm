#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include "binary_tree.h"

namespace algo
{
	template<typename T>
	class BinarySearchTree : public BinaryTree<T>
	{
	public:
		BinarySearchTree() { root = NULL; }
		~BinarySearchTree() { }
		void add(const T& data);

		void showSorted() const { this->traverseInorder(); }

	private:
		void _addData(const T& data, BinaryNode<T>* node);
	};

	template<typename T>
	void BinarySearchTree<T>::add(const T& data)
	{
		if (root == NULL)
		{
			root = new BinaryNode<T>;
			root->item = data;
		}
		else
		{
			_addData(data, root);
		}
	}

	template<typename T>
	void BinarySearchTree<T>::_addData(const T& data, BinaryNode<T>* node)
	{
		// node is not NULL
		if (data > node->item)
		{
			// add right
			if (node->right == NULL)
				node->right = new BinaryNode<T>(data);
			else
				_addData(data, node->right);
		}
		else
		{
			// add left
			if (node->left == NULL)
				node->left = new BinaryNode<T>(data);
			else
				_addData(data, node->left);
		}
	}
}

#endif
