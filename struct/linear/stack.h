#ifndef STACK_H
#define STACK_H

#include "list.h"

namespace algo
{
	template<typename T>
	class ArrayStack
	{
	private:
		T* data;
		int capacity;
		int size;
	public:
		ArrayStack(int max_size);
		void push(const T& data);
		void pop();
		const T& top() const;
		T& top();
		bool isEmpty() const;
	};

	template<typename T>
	class ListStack
	{
	private:
		List<T> list;
	public:
		ListStack();
		~ListStack();
		void push(const T& data);
		void pop();
		const T& top() const;
		T& top();
		bool isEmpty() const;
	};
}

#endif
