#include "max_sub_array.h"
#include "../../utils/minmax.h"
#include <iostream>

double MaxSubArray::bruteForce(double *array, int size)
{
    if (size == 0)
        return 0;
    else if (size == 1 && array[0] >= 0)
        return array[0];
    else if (size == 1 && array[0] < 0)
        return 0;
    
    double max_sum = 0;
    for (int i = 0; i < size; ++i)
    {
        for (int j = i; j < size; ++j)
        {
            double sum = 0;
            for (int k = i; k <= j; ++k)
                sum += array[k];
            if (sum > max_sum)
                max_sum = sum;
        }
    }
    return max_sum;
}

double MaxSubArray::dc(double *array, int left, int right)
{
    if (left == right)
        return array[left];
    
    int mid = (left + right) / 2;
    double m1 = dc(array, left, mid);
    double m2 = dc(array, mid + 1, right);
    
    // search middle
    double now = array[mid];
    double left_sum = now;
    for (int i = mid - 1; i >= left; --i)
    {
        now += array[i];
        left_sum = MAX(now, left_sum);
    }
    
    double right_sum = array[mid + 1];
    now = array[mid + 1];
    for (int i = mid + 2; i <= right; ++i)
    {
        now += array[i];
        right_sum = MAX(now, right_sum);
    }
    
    double m3 = left_sum + right_sum;
    return MAX3(m1, m2, m3);
}


double MaxSubArray::dc(double* array, int size)
{
    if (size == 0)
        return 0;
    else if (size == 1 && array[0] >= 0)
        return array[0];
    else if (size == 1 && array[0] < 0)
        return 0;
    
    return dc(array, 0, size - 1);
}

double MaxSubArray::dp(double *array, int size)
{
    if (size == 0)
        return 0;
    else if (size == 1 && array[0] >= 0)
        return array[0];
    else if (size == 1 && array[0] < 0)
        return 0;
    
    double result = array[0];
    double sum = array[0];
    for (int i = 1; i < size; ++i)
    {
        if (sum > 0)
            sum += array[i];
        else
            sum = array[i];
        
        if (sum > result)
            result = sum;
        // std::cout << sum << ", " << result << std::endl;
    }
    return result;
}
