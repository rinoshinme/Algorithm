#ifndef BASIC_SORT_H
#define BASIC_SORT_H

#include "sort_utils.h"

namespace algo
{
	template<typename T>
	class BasicSort : public SortUtils<T>
	{
	public:
		virtual void sort(T* array, int size) const {}
		void selectionSort(T* array, int size);
		void insertionSort(T* array, int size);
		void bubbleSort(T* array, int size) {}
	};

	template<typename T>
	void BasicSort<T>::selectionSort(T* array, int size)
	{
		for (int i = 0; i < size; ++i)
		{
			int min = i;
			for (int j = i + 1; j < size; ++j)
			{
				if (less(array[j], array[min]))
					min = j;
			}
			exch(array, i, min);
		}
	}

	template<typename T>
	void BasicSort<T>::insertionSort(T* array, int size)
	{
		for (int i = 1; i < size; ++i)
		{
			for (int j = i; j > 0; --j)
			{
				if (less(array[j], array[j - 1]))
					exch(array, j, j - 1);
			}
		}
	}

}

#endif
