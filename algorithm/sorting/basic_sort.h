#ifndef BASIC_SORT_H
#define BASIC_SORT_H

#include "sort_utils.h"

namespace algo
{
	template<typename T>
	class BasicSort : public SortUtils<T>
	{
	public:
		void bubbleSort(T* array, int size);
		void selectionSort(T* array, int size);

	};

	template<typename T>
	void BasicSort<T>::bubbleSort(T* array, int size)
	{

	}

	template<typename T>
	void BasicSort<T>::selectionSort(T* array, int size)
	{

	}

}

#endif
