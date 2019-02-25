#ifndef SORT_UTILS_H
#define SORT_UTILS_H

namespace algo
{
	template<typename T>
	class SortUtils
	{
	public:
		void exch(T* a, int i, int j) const
		{
			T temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}

		// can be overrided for special value type
		virtual int comp(const T& v, const T& w) const
		{
			if (v < w)
				return -1;
			else if (v == w)
				return 0;
			else
				return 1;
		}

		bool isSorted(const T* array, int size) const
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
	};
}

#endif
