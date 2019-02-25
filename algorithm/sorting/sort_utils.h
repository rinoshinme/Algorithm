/*
 * Adapted from Algorithms 4th Edition by Sedgewick.
 */
#ifndef SORT_UTILS_H
#define SORT_UTILS_H

#include <iostream>
#include <ctime>

namespace algo
{
	template<typename T>
	class SortUtils
	{
	public:
		SortUtils() {}
		virtual ~SortUtils() {}
		virtual void sort(T* array, int size) = 0;

	public:
		// can be overrided for special value type
		virtual int compare(const T& v, const T& w)
		{
			if (v < w)
				return -1;
			else if (v == w)
				return 0;
			else
				return 1;
		}

		bool isSorted(const T* array, int size)
		{
			if (size == 0 || size == 1)
				return true;
			for (int i = 0; i < size - 1; ++i)
			{
				if (array[i] > array[i + 1])
					return false;
			}
			return true;
		}

		void show(const T* array, int size, char sep = '\n')
		{
			for (int i = 0; i < size; ++i)
				std::cout << array[i] << sep;
			std::cout << std::endl;
		}

		virtual double timeSort(T* array, int size)
		{
			clock_t begin = clock();
			sort(array, size);
			clock_t end = clock();
			return (end - begin) * 1.0 / CLOCKS_PER_SEC;
		}

	protected:
		void exch(T* a, int i, int j)
		{
			T temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}

		virtual bool less(const T& v, const T& w)
		{
			return (v < w);
		}

	};
}

#endif
