/*
 * permutation of string
 */
#ifndef string_permutation_h
#define string_permutation_h

#include <string>

namespace algo
{
    class StringPermutation
    {
    public:
        void permute(char* input, int size);
        void permuteRepeat(char* input, int size);
        
        // TODO
        void permuteNonRecursive(char* input, int size);
        
    private:
        void _permute(char* input, int from, int to);
        void _permute_repeat(char* input, int from, int to);
        
        void _swap(char* input, int i, int j);
    };
}

#endif /* string_permutation_h */
