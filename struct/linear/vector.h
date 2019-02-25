#ifndef VECTOR_H
#define VECTOR_H

namespace algo
{
	template<typename T>
	class Vector
	{
		T* data;
		int capacity;
		int size;
	public:
		Vector();
		~Vector();
		void pushBack(const T& data);
		const T& operator[](int index) const;
		T& operator[](int index);
	};
}

#endif
