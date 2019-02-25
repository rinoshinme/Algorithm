#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <vector>

namespace algo
{
	template<typename T>
	struct BinaryNode
	{
		BinaryNode<T>* left;
		BinaryNode<T>* right;
		T data;
		BinaryNode() { left = NULL; right = NULL; }
		BinaryNode(const T& data, BinaryNode<T>* l = NULL, BinaryNode<T>* r = NULL)
		{
			this->data = data;
			left = l;
			right = r;
		}
	};

	template<typename T>
	class BinaryTree
	{
		BinaryNode<T>* root;
	public:
		BinaryTree();
		void loadFromData();
		void clearTree();
		void traverseInorder();
		void traversePreorder();
		void traversePostorder();

		int height(); // recursive implementation

	private:
		// recursive methods.
		void clearSubTree(BinaryNode<T>* node);
		int heightOfSubTree(BinaryNode<T>* node);
		void traverseInorderSubTree(BinaryNode<T>* node);
		void traversePreorderSubTree(BinaryNode<T>* node);
		void traversePostorderSubTree(BinaryNode<T>* node);
	};

	template<typename T>
	BinaryTree<T>::BinaryTree()
	{
		root = NULL;
	}

	template<typename T>
	void BinaryTree<T>::clearTree()
	{
		if (root != NULL)
			clearSubTree(root);
	}


}

#endif
