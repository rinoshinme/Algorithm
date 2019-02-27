#include "hash.h"

namespace algo
{
    unsigned long djb2(unsigned char* str)
    {
        unsigned long hash = 5381;
        int c;
        while (c = *str++)
        {
            hash = ((hash << 5) + hash) + c;
        }
        return hash;
    }
    
    unsigned long sdbm(unsigned char* str)
    {
        unsigned long hash = 0;
        int c;
        while (c = *str++)
        {
            hash = c + (hash << 6) + (hash << 16) - hash;
        }
        return hash;
    }
}
