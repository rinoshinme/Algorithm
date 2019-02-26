#ifndef BST_H
#define BST_H

#include "symbol_table.h"

namespace algo
{
	template<typename Key, typename Value>
	struct BSTNode : public SymbolTable<Key, Value>
	{
		Key key;
		Value val;
		BSTNode* left;
		BSTNode* right;
		int N;	// number of nodes in subtree
		
		BSTNode(Key& key, value& val, int N)
		{
			this->key = key;
			this->val = val;
			this->N = N;
			this->left = NULL;
			this->right = NULL;
		}
	};

	template<typename Key, typename Value>
	class BST
	{
	private:
		BSTNode<Key, Value>* root;

	public:
		BST() { root = NULL; }
		~BST();
		int size() { return _size(root); }
		bool get(const Key& key, Value& val) { return _get(root, key); }
		void put(const Key& key, const Value& val) { root = _put(root, key, val); }

		bool min(Key& key);
		bool max(Key& key);

	private:
		int _size(BSTNode<Key, Value>* node);
		bool _get(BSTNode<Key, Value>* node, const Key& key, Value& val);
		BSTNode<Key, Value>* _put(BSTNode<Key, Value>* node, const Key& key, const Value& val);

		BSTNode<Key, Value>* _min(BSTNode<Key, Value>* node);
		BSTNode<Key, Value>* _max(BSTNode<Key, Value>* node);

	};

	template<typename Key, typename Value>
	int BST<Key, Value>::_size(BSTNode<>* node)
	{
		if (node == NULL)
			return 0;
		else
			return node->N;
	}

	template<typename Key, typename Value>
	bool BST<Key, Value>::_get(BSTNode<Key, Value>* node, const Key& key, Value& val)
	{
		if (node == NULL)
			return false;
		int cmp = compare(key, node->key);
		if (cmp < 0)
			return _get(node->left, key, val);
		else if (cmp > 0)
			return _get(node->right, key, val);

		val = node->val;
		return true;
	}

	template<typename Key, typename Value>
	BSTNode<Key, Value> BST<Key, Value>::_put(BSTNode<Key, Value>* node, const Key& key, const Value& val)
	{
		if (node == NULL)
			return new BSTNode<Key, Value>(key, val, 1);
		int cmp = compare(key, node->key);
		if (cmp < 0)
			node->left = _put(node->left, key, val);
		else if (cmp > 0)
			node->right = put(node->right, key, val);
		else
			node->val = val;
		node->N = size(node->left) + size(node->right) + 1;
		return node;
	}
}

#endif
