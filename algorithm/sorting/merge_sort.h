#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include "sort_utils.h"

#ifndef MIN
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#endif

namespace algo
{
	template<typename T>
	class MergeSort : public SortUtils<T>
	{
	private:
		mutable T* aux;

	public:
		MergeSort()
		{
			int MAX_ARRAY_SIZE = 1000;
			aux = new T[MAX_ARRAY_SIZE];
			memset(aux, 0, MAX_ARRAY_SIZE * sizeof(T));
		}

		~MergeSort() { delete[] aux; }

		virtual void sort(T* array, int size) { _sort(array, 0, size - 1); }
		// bottom up sort, no recursion
		void sortBU(T* array, int size);

	private:
		void _sort(T* array, int low, int high);
		void _merge(T* array, int low, int mid, int high);
	};

	template<typename T>
	void MergeSort<T>::_merge(T* array, int low, int mid, int high)
	{
		int i = low;
		int j = mid + 1;
		for (int k = low; k <= high; ++k)
			aux[k] = array[k];

		for (int k = low; k <= high; ++k)
		{
			if (i > mid)
				array[k] = aux[j++];
			else if (j > high)
				array[k] = aux[i++];
			else if (less(aux[j], aux[i]))
				array[k] = aux[j++];
			else
				array[k] = aux[i++];
		}
	}

	template<typename T>
	void MergeSort<T>::_sort(T* array, int low, int high)
	{
		if (high <= low)
			return;
		int mid = low + (high - low) / 2;
		_sort(array, low, mid);
		_sort(array, mid + 1, high);
		_merge(array, low, mid, high);
	}

	template<typename T>
	void MergeSort<T>::sortBU(T* array, int size)
	{
		for (int sz = 1; sz < size; sz = sz + sz)
		{
			for (int lo = 0; lo < size - sz; lo += sz + sz)
				_merge(array, lo, lo + sz - 1, MIN(lo + sz + sz - 1, size - 1));
		}
	}
}

#endif
