#ifndef QUEUE_H
#define QUEUE_H

#include "list.h"

namespace algo
{
	template<typename T>
	class Queue
	{
		List<T> list;
	public:
		Queue() {}
		~Queue() {}

		void push(const T& data);
		void pop();
		const T& front() const;
		T& front();
		const T& back() const;
		T& back();
		int size();
	};
}

#endif
