#ifndef DEQUE_H
#define DEQUE_H

#include "list.h"

namespace algo
{
	template<typename>
	class Deque
	{
		List<T> list;
	public:
		void pushFront(const T& data);
		void pushBack(const T& data);
		void popFront();
		void popBack();
		const T& front() const;
		T& front();
		const T& back() const;
		T& back();
	};
}

#endif
