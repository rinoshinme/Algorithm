#include "algorithm/examples/max_sub_array.h"
#include "algorithm/examples/string_shift.h"
#include "algorithm/examples/string_permutation.h"
#include "algorithm/examples/string_dp.h"
#include "utils/image_utils.h"

#include <iostream>
using namespace algo;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    std::string s1("caoffe");
    std::string s2("coffee");
    StringDP sdp;
    std::string result;
    int d = sdp.lcs1(s1, s2, result);
    std::cout << "-" << result << "-" << std::endl;
    
    // sdp.showValues(s1.size(), s2.size());
    std::cout << d << std::endl;
    
    // printf("%s\n", input);
	
#ifdef _WIN32
	std::cout << "finished...\n";
	std::getchar();
#endif
    return 0;
}
