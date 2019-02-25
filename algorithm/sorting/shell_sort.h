#ifndef SHELL_SORT_H
#define SHELL_SORT_H

#include "sort_utils.h"

namespace algo
{
	template<typename T>
	class ShellSort : public SortUtils<T>
	{
	public:
		virtual void sort(T* array, int size) const
		{
			int h = 1;
			while (h < size / 3)
				h = h * 3 + 1;
			while (h >= 1)
			{
				for (int i = h; i < size; ++i)
				{
					for (int j = i; j >= h; j -= h)
						if (less(array[j], array[j - h]))
							exch(array, j, j - h);
				}
				h = h / 3;
			}
		}
	};
}

#endif
