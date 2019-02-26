#include "string_dp.h"
#include "../../utils/minmax.h"
#include <iostream>
#include <algorithm>

namespace algo
{
    int StringDP::lcs(const std::string &s1, const std::string &s2, std::string& result)
    {
        int size1 = int(s1.size());
        int size2 = int(s2.size());
        if (size1 == 0 || size2 == 0)
        {
            result.clear();
            return 0;
        }
        memset(data, 0, max_size * max_size * sizeof(int));
        memset(direction, 0, max_size * max_size * sizeof(int));
        
        for (int i = 0; i < size1; ++i)
            value(i, 0) = 0;
        for (int j = 0; j < size2; ++j)
            value(0, j) = 0;
        
        for (int j = 1; j <= size2; ++j)
        {
            for (int i = 1; i <= size1; ++i)
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    value(i, j) = value(i - 1, j - 1) + 1;
                    marker(i, j) = TOP_LEFT;
                }
                else
                {
                    int d1 = value(i, j - 1);
                    int d2 = value(i - 1, j);
                    if (d1 > d2)
                    {
                        value(i, j) = d1;
                        marker(i, j) = TOP;
                    }
                    else
                    {
                        value(i, j) = d2;
                        marker(i, j) = LEFT;
                    }
                }
            }
        }
        int size = value(size1, size2);
        // calculate result string
        result.resize(size);
        int x = size1;
        int y = size2;
        int idx = size - 1;
        while (idx >= 0)
        {
            int dir = marker(x, y);
            if (dir == LEFT)
                x -= 1;
            else if (dir == TOP)
                y -= 1;
            else if (dir == TOP_LEFT)
            {
                result[idx] = s1[x - 1]; // s1[x-1] == s2[y-1]
                x -= 1;
                y -= 1;
                idx -= 1;
            }
        }
        
        return size;
    }
    
    int StringDP::lcs1(const std::string &s1, const std::string &s2, std::string& result)
    {
        int size1 = int(s1.size());
        int size2 = int(s2.size());
        if (size1 == 0 || size2 == 0)
        {
            result.clear();
            return 0;
        }
        
        memset(data, 0, max_size * max_size * sizeof(int));
        memset(direction, 0, max_size * max_size * sizeof(int));
        
        for (int i = 0; i < size1; ++i)
            value(i, 0) = 0;
        for (int j = 0; j < size2; ++j)
            value(0, j) = 0;
        
        for (int j = 1; j <= size2; ++j)
        {
            for (int i = 1; i <= size1; ++i)
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    value(i, j) = value(i - 1, j - 1) + 1;
                    marker(i, j) = TOP_LEFT;
                }
                else
                {
                    value(i, j) = 0;
                    marker(i, j) = NONE;
                }
            }
        }
        
        // find max value in value array
        int max_x = 0;
        int max_y = 0;
        int max_length = 0;
        for (int y = 1; y <= size2; ++y)
        {
            for (int x = 1; x <= size1; ++x)
            {
                if (value(x, y) > max_length)
                {
                    max_length = value(x, y);
                    max_x = x;
                    max_y = y;
                }
            }
        }
        result = s1.substr(max_x - max_length, max_length);
        return max_length;
    }
    
    int StringDP::lis(const std::string &input, std::string &result)
    {
        // optimal algorithm for lis has complexity O(nlogn)
        // this method has complexity O(n^2)
        std::string sorted = input;
        std::sort(sorted.begin(), sorted.end());
        return lcs(input, sorted, result);
    }
    
    int StringDP::editDistance(const std::string &s1, const std::string &s2)
    {
        size_t size1 = s1.size();
        size_t size2 = s2.size();
        if (size1 == 0)
            return int(size2);
        else if (size2 == 0)
            return int(size1);
        
        memset(data, 0, max_size * max_size * sizeof(int));
        
        for (int i = 0; i < size1; ++i)
            value(i, 0) = i;
        for (int j = 0; j < size2; ++j)
            value(0, j) = j;
        
        for (int j = 1; j < size2; ++j)
        {
            for (int i = 1; i < size1; ++i)
            {
                if (s1[i] == s2[j])
                    value(i, j) = value(i - 1, j - 1);
                else
                {
                    int d1 = value(i, j - 1);
                    int d2 = value(i - 1, j);
                    int d3 = value(i - 1, j - 1);
                    value(i, j) = MIN3(d1, d2, d3) + 1;
                }
            }
        }
        return value(int(size1) - 1, int(size2) - 1);
    }
    
    void StringDP::showValues(int width, int height)
    {
        for (int y = 0; y <= height; ++y)
        {
            for (int x = 0; x <= width; ++x)
                std::cout << value(x, y);
            std::cout << std::endl;
        }
    }
}
