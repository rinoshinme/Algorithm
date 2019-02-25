#include "string_shift.h"

namespace algo
{
    void StringShift::shiftLeft(char *input, int size, int k)
    {
        int m = k % size;
        stringReverse(input, 0, m - 1);
        stringReverse(input, m, size - 1);
        stringReverse(input, 0, size - 1);
    }
    
    void StringShift::stringReverse(char *input, int begin, int end)
    {
        int length = (end - begin + 1);
        for (int i = 0; i < length / 2; ++i)
        {
            char temp = input[begin + i];
            char temp2 = input[begin + length - 1 - i];
            input[begin + i] = temp2;
            input[begin + length - 1 - i] = temp;
        }
    }
}
