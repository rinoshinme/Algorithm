/*
 * Implementation of doubly linked list
 */
#ifndef DOUBLE_LIST_H
#define DOUBLE_LIST_H

namespace algo
{
	template<typename T>
	struct DoubleListNode
	{
		DoubleListNode<T>* next;
		DoubleListNode<T>* prev;
		T data;
		DoubleListNode() { next = NULL; prev = NULL; }
		DoubleListNode(const T& item, DoubleListNode<T>* n = NULL, DoubleListNode<T>* p = NULL)
		{
			next = n;
			prev = p;
			data = item;
		}
	};

	template<typename T>
	class DoubleList
	{
	private:
		DoubleListNode<T>* head;
		DoubleListNode<T>* tail;

	public:
		DoubleList();
		~DoubleList();

		bool isEmpty() const;
		void addToHead(const T& data);
		void addToTail(const T& data);
		void deleteFromHead();
		void deleteFromTail();
		const T& headData() const { return head->next->data; }
		const T& tailData() const { return tail->prev->data; }

		bool isInList(const T& data) const;
		void emptyList();
	};

	template<typename T>
	DoubleList<T>::DoubleList()
	{
		head = new DoubleListNode<T>;
		tail = new DoubleListNode<T>;
		head->next = tail;
		tail->prev = head;
	}

	template<typename T>
	DoubleList<T>::~DoubleList()
	{
		emptyList();
	}

	template<typename T>
	bool DoubleList<T>::isEmpty() const
	{
		return (head->next == tail);
	}

	template<typename T>
	void DoubleList<T>::addToHead(const T& data)
	{
		DoubleListNode<T>* node = new DoubleListNode<T>(data);
		node->next = head->next;
		node->prev = head;
		head->next->prev = node;
		head->next = node;
	}

	template<typename T>
	void DoubleList<T>::addToTail(const T& data)
	{
		DoubleListNode<T>* node = new DoubleListNode<T>(data);
		node->next = tail;
		node->prev = tail->prev;
		tail->prev->next = node;
		tail->prev = node;
	}

	template<typename T>
	void DoubleList<T>::deleteFromHead()
	{
		if (head->next == tail)
			return; // no item to delete
		DoubleListNode<T>* temp = head->next;
		head->next = temp->next;
		temp->next->prev = head;
		delete temp;
	}

	template<typename T>
	void DoubleList<T>::deleteFromTail()
	{
		if (head->next == tail)
			return;
		DoubleListNode<T>* temp = tail->prev;
		tail->prev = temp->prev;
		temp->prev->next = tail;
		delete temp;
	}

	template<typename T>
	bool DoubleList<T>::isInList(const T& data) const
	{
		DoubleListNode<T>* temp = head->next;
		while (temp->data != data && temp != tail)
			temp = temp->next;
		if (temp == tail)
			return false;
		else
			return true;
	}

	template<typename T>
	void DoubleList<T>::emptyList()
	{
		while (head->next != tail)
			deleteFromHead();
	}

}


#endif
