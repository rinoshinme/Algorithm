#ifndef HEAP_SORT_H
#define HEAP_SORT_H

#include "sort_utils.h"

namespace algo
{
	template<typename T>
	class HeapSort : public SortUtils < T >
	{
		// PROBLEM
	public:
		void sort(T* array, int size)
		{
			int N = size;
			for (int k = N / 2; k >= 1; --k)
				sink(array, k, N);
			while (N > 1)
			{
				exch(array, 1, N--);
				sink(array, 1, N);
			}
		}

	private:
		void sink(T* array, int k, int size)
		{
			while (2 * k <= size)
			{
				int j = 2 * k;
				if (j < N && less(array[j], array[j + 1]))
					++j;
				if (!less(array[k], array[j]))
					break;
				k = j;
			}
		}
	};
}

#endif
