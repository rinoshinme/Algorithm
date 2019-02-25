#ifndef TEST_LIST_H
#define TEST_LIST_H

#include "..\struct\linear\list.h"
#include "tester.h"

namespace algo
{
	inline void test_list()
	{
		List<int> list;
		for (int i = 0; i < 10; ++i)
			list.addToHead(i);
		bool in = list.isInList(5);
		std::cout << (in ? "true" : "false") << std::endl;
	}
}

#endif
