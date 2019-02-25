#ifndef COMPARE_H
#define COMPARE_H

/* general purpose comparator */
template<typename T>
class Comparator
{
public:
	int operator()(T a, T b)
	{
		if (a < b)
			return -1;
		else if (a > b)
			return 1;
		else
			return 0;
	}
};

#endif
