#ifndef minmax_h
#define minmax_h

#ifndef MIN
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#endif

#ifndef MAX
#define MAX(a, b) ((a) < (b) ? (b) : (a))
#endif

template<typename T>
T MAX3(T a, T b, T c)
{
    if (a < b)
        return MAX(b, c);
    else
        return MAX(a, c);
}

template<typename T>
T MIN3(T a, T b, T c)
{
    if (a < b)
        return MIN(a, c);
    else
        return MIN(b, c);
}

#endif /* minmax_h */
