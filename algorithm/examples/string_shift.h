/*
 * rotational shift of sequence of chars
 */
#ifndef string_shift_h
#define string_shift_h

namespace algo
{
    class StringShift
    {
    public:
        // shift string input k steps to left
        void shiftLeft(char* input, int size, int k);
        
    private:
        void stringReverse(char* input, int begin, int end);
    };
}

#endif /* string_shift_h */
