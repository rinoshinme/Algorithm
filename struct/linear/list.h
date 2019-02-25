/*
 * Implementation of singly linked list
 */
#ifndef ALGO_LIST_H
#define ALGO_LIST_H

#include <cstdlib>

namespace algo
{
	/* type T should have default constructor */
	template<typename T>
	struct ListNode
	{
		ListNode<T>* next;
		T data;

		// use default constructor if does not care data
		ListNode() { next = NULL; }
		ListNode(const T& item, ListNode<T>* ptr = NULL)
		{
			data = item;
			next = ptr;
		}
	};

	template<typename T>
	class List
	{
	private:
		ListNode<T>* head;
		ListNode<T>* tail;
		int num_nodes;
	public:
		List();
		~List();
		bool isEmpty() const { return head == NULL; }
		int numNodes() const { return num_nodes; }
		void addToHead(const T& data);
		void addToTail(const T& data);
		void deleteFromHead();
		void deleteFromTail();
		// no exception handling for headData and tailData
		const T& headData() const { return head->data; }
		const T& tailData() const { return tail->data; }

		void deleteNode(const T& data);
		bool isInList(const T& data) const;

	private:
		void clearNodes();
	};

	/* implementation */
	template<typename T>
	List<T>::List()
	{
		head = NULL;
		tail = NULL;
		num_nodes = 0;
	}

	template<typename T>
	List<T>::~List()
	{
		clearNodes();
	}

	template<typename T>
	void List<T>::addToHead(const T& data)
	{
		ListNode<T>* node = new ListNode<T>(data);
		node->next = head;
		head = node;
		if (tail == NULL)
			tail = head;
		num_nodes += 1;
	}

	template<typename T>
	void List<T>::addToTail(const T& data)
	{
		if (tail == NULL)
		{
			addToHead(data);
		}
		else
		{
			ListNode<T>* node = new ListNode<T>(data);
			tail->next = node;
			tail = node;
			num_nodes += 1;
		}
	}

	template<typename T>
	void List<T>::deleteFromHead()
	{
		if (head == NULL && tail == NULL)
			return; // no element in list
		ListNode<T>* temp = head;
		if (head == tail)
		{
			// only 1 element in list
			head = NULL;
			tail = NULL;
		}
		else
		{
			head = head->next;
		}
		delete temp;
		num_nodes -= 1;
	}

	template<typename T>
	void List<T>::deleteFromTail()
	{
		if (head == NULL && tail == NULL)
			return;
		if (head == tail)
		{
			delete head;
			head = NULL;
			tail = NULL;
		}
		else
		{
			ListNode<T>* temp = head;
			while (temp->next != tail)
				temp = temp->next;
			delete tail;
			tail = temp;
			tail->next = NULL;
		}
		num_nodes -= 1;
	}

	template<typename T>
	void List<T>::deleteNode(const T& data)
	{
		if (head == NULL && tail == NULL)
			return;
		if (head == tail && head->data == data)
		{
			delete head;
			head = NULL;
			tail = NULL;
		}
		else
		{
			if (head->data == data)
			{
				ListNode<T>* temp = head;
				head = head->next;
				delete temp;
			}
			else
			{
				ListNode<T>* prev = head;
				ListNode<T>* temp = head->next;
				while (temp->data != data && temp!= NULL)
				{
					prev = temp;
					temp = temp->next;
				}
				if (temp != NULL)
				{
					prev->next = temp->next;
					if (temp == tail)
						tail = prev;
					delete temp;
				}
			}
		}
		num_nodes -= 1;
	}

	template<typename T>
	bool List<T>::isInList(const T& data) const
	{
		ListNode<T>* node;
		for (node = head; node->next != NULL; node = node->next)
		{
			if (node->data == data)
				return true;
		}
		return false;
	}

	template<typename T>
	void List<T>::clearNodes()
	{
		while (head != NULL)
			deleteFromHead();
	}

}



#endif
