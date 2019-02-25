#include "string_permutation.h"

#include <iostream>

namespace algo
{
    void StringPermutation::permute(char* input, int size)
    {
        _permute(input, 0, size - 1);
    }
    
    void StringPermutation::permuteRepeat(char *input, int size)
    {
        _permute_repeat(input, 0, size - 1);
    }
    
    void StringPermutation::_permute(char *input, int from, int to)
    {
        if (from == to)
        {
            // output sequence
            for (int i = 0; i <= to; ++i)
                std::cout << input[i];
            std::cout << "\n";
            return;
        }
        for (int i = from; i <= to; ++i)
        {
            _swap(input, i, from);
            _permute(input, from + 1, to);
            _swap(input, i, from);
        }
    }
    
    void StringPermutation::_permute_repeat(char *input, int from, int to)
    {
        if (from == to)
        {
            // output sequence
            for (int i = 0; i <= to; ++i)
                std::cout << input[i];
            std::cout << "\n";
            return;
        }
        
        int marker[256];
        memset(marker, 0, 256 * sizeof(int));
        
        for (int i = from; i <= to; ++i)
        {
            if (marker[input[i]] == 1)
                continue;
            marker[input[i]] = 1;
            _swap(input, i, from);
            _permute_repeat(input, from + 1, to);
            _swap(input, i, from);
        }
    }
    
    void StringPermutation::_swap(char *input, int i, int j)
    {
        char temp = input[i];
        input[i] = input[j];
        input[j] = temp;
    }
}
