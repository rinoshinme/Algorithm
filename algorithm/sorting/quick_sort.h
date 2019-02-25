#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include "sort_utils.h"

namespace algo
{
	template<typename T>
	class QuickSort : public SortUtils<T>
	{
	public:
		void sort(T* array, int size) { _sort(array, 0, size - 1); }
		/* 3 way sort for arrays with many repeated items, in Page 189 */ 
		void sort3Way(T* array, int size) {}

	private:
		void _sort(T* array, int low, int high);
		int _partition(T* array, int low, int high);
	};

	template<typename T>
	void QuickSort<T>::_sort(T* array, int low, int high)
	{
		if (high <= low)
			return;
		
		// switch to insertion sort
		// see Page 187 Algorithm by Sedgewick (Chinese Edition) 

		int j = _partition(array, low, high);
		_sort(array, low, j - 1);
		_sort(array, j + 1, high);
	}

	template<typename T>
	int QuickSort<T>::_partition(T* array, int low, int high)
	{
		int i = low;
		int j = high + 1;
		T v = array[low];
		while (true)
		{
			// search left for large item
			while (less(array[++i], v))
			{
				if (i == high)
					break;
			}
			// search right for small item
			while (less(v, array[--j]))
			{
				if (j == low)
					break;
			}

			if (i >= j)
				break;
			exch(array, i, j);
		}
		exch(array, low, j);
		return j;
	}
}

#endif
