#include <iostream>
#include "tests/test_list.h"
#include "tests/test_double_list.h"
#include "tests/test_binary_search_tree.h"
#include "tests/test_sort.h"

using namespace algo;

int main()
{
	// test_list();
	// test_double_list();
	// test_binary_search_tree();
	test_sort();

	std::cout << "finished...\n";
	std::getchar();
}
