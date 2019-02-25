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
		T item;
		BinaryNode() { left = NULL; right = NULL; }
		BinaryNode(const T& data, BinaryNode<T>* l = NULL, BinaryNode<T>* r = NULL)
		{
			this->item = data;
			left = l;
			right = r;
		}
	};

	template<typename T>
	class BinaryTree
	{
	protected:
		BinaryNode<T>* root;

	public:
		BinaryTree();
		virtual ~BinaryTree();
		// void loadFromData();
		virtual void clearTree() { if (root) _clearSubTree(root); }
		virtual int height() const { return _heightOfSubTree(root); } // recursive implementation
		// int depth(BinaryNode<T>* node); // depth of a node.

		virtual void traverseInorder() const { _traverseInorderSubTree(root); }
		virtual void traversePreorder() const { _traversePreorderSubTree(root); }
		virtual void traversePostorder() const { _traversePostorderSubTree(root); }

	private:
		// recursive methods.
		void _clearSubTree(BinaryNode<T>* node);
		int _heightOfSubTree(const BinaryNode<T>* node) const;

		void _traverseInorderSubTree(const BinaryNode<T>* node) const;
		void _traversePreorderSubTree(const BinaryNode<T>* node) const;
		void _traversePostorderSubTree(const BinaryNode<T>* node) const;
	};

	template<typename T>
	BinaryTree<T>::BinaryTree()
	{
		root = NULL;
	}

	template<typename T>
	BinaryTree<T>::~BinaryTree()
	{
		clearTree();
	}

	template<typename T>
	int BinaryTree<T>::_heightOfSubTree(const BinaryNode<T>* node) const
	{
		if (node == NULL)
			return 0;
		int h_left = _heightOfSubTree(node->left);
		int h_right = _heightOfSubTree(node->right);
		return (h_left > h_right) ? h_left : h_right;
	}

	template<typename T>
	void BinaryTree<T>::_traverseInorderSubTree(const BinaryNode<T>* node) const
	{
		if (node == NULL)
			return;
		_traverseInorderSubTree(node->left);
		std::cout << node->item << std::endl;
		_traverseInorderSubTree(node->right);
	}

	template<typename T>
	void BinaryTree<T>::_traversePreorderSubTree(const BinaryNode<T>* node) const
	{
		if (node == NULL)
			return;
		std::cout << node->item << std::endl;
		_traverseInorderSubTree(node->left);
		_traverseInorderSubTree(node->right);
	}

	template<typename T>
	void BinaryTree<T>::_traversePostorderSubTree(const BinaryNode<T>* node) const
	{
		if (node == NULL)
			return;
		_traverseInorderSubTree(node->left);
		_traverseInorderSubTree(node->right);
		std::cout << node->item << std::endl;
	}

	template<typename T>
	void BinaryTree<T>::_clearSubTree(BinaryNode<T>* node)
	{
		if (node == NULL)
			return;

		if (node->left)
			_clearSubTree(node->left);
		if (node->right)
			_clearSubTree(node->right);

		delete node;
		node = NULL;
	}
}

#endif
