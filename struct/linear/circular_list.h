#ifndef CIRCULAR_LIST_H
#define CIRCULAR_LIST_H

#include "list.h"

namespace algo
{
	template<typename T>
	class CircularList
	{
	private:
		ListNode<T>* head;

	public:
		CircularList();
		~CircularList();
		void addNode(const T& data);
		void showList() const;
	};
}

#endif
