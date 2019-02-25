#ifndef kmp_h
#define kmp_h

#include <vector>
#include <string>

namespace algo
{
    // kmp algorithm, find pattern from input string
    class KMP
    {
    private:
        std::vector<int> next;
    public:
        // 56min
        int bruteForce(const std::string& s, const std::string& p);
        
        int kmp();
        
    private:
        void createNext(const std::string& pattern);
        
        
    };
    
}

#endif /* kmp_h */
