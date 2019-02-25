#ifndef max_sub_array_h
#define max_sub_array_h

class MaxSubArray
{
public:
    // brute force algo, O(n^3) complexity
    double bruteForce(double* array, int size);
    
    // divide and conquer algo, O(nlogn) complexity
    double dc(double* array, int size);
    double dc(double* array, int left, int right);
    
    // analysis
    double analy(double* array, int size);
    // dynamic programming, linear algorithm
    // s[i+1] = max(s[i] + a[i+1], a[i+1])
    double dp(double* array, int size);
};

#endif /* max_sub_array_h */
