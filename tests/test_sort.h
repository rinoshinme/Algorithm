#ifndef TEST_SORT_H
#define TEST_SORT_H

#include "..\algorithm\sorting\basic_sort.h"
#include "..\algorithm\sorting\shell_sort.h"

namespace algo
{
	inline void test_sort()
	{
		BasicSort<int> bs;
		ShellSort<int> ss;

		int a[] = { 0, 2, 1, 6, 9, 8, 5, 4, 7, 3 };
		bs.insertionSort(a, 10);
		bs.show(a, 10, ' ');

		int b[] = { 0, 2, 1, 6, 9, 8, 5, 4, 7, 3 };
		bs.selectionSort(b, 10);
		bs.show(b, 10, ' ');
		
		int c[] = { 0, 9, 7, 6, 5, 2, 3, 1, 4, 8 };
		ss.sort(c, 10);
		ss.show(c, 10, ' ');
	}
}

#endif
