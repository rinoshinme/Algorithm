/*
 * Dynamic Programming for sequence of chars
 * from 七月视频教程中关于算法的第二讲
 */
#ifndef string_dp_h
#define string_dp_h

#include <string>

namespace algo
{
    class StringDP
    {
    private:
        // temporary data for dynamic programming
        int* data;
        int* direction;
        int max_size;
        const int NONE = 0;
        const int LEFT = 1;
        const int TOP = 2;
        const int TOP_LEFT = 3;
        
    public:
        StringDP(int max_string_size = 1000)
        {
            max_size = max_string_size + 1;
            data = new int[max_size * max_size];
            direction = new int[max_size * max_size];
            memset(data, 0, max_size * max_size * sizeof(int));
            memset(direction, 0, max_size * max_size * sizeof(int));
        }
        
        // longest common sequence
        int lcs(const std::string& s1, const std::string& s2, std::string& result);
        // longest common substring
        int lcs1(const std::string& s1, const std::string& s2, std::string& result);
        // longest increasing subsequence
        int lis(const std::string& input, std::string& result);
        // edit distance
        int editDistance(const std::string& s1, const std::string& s2);
        
        void showValues(int width, int height);
        
    private:
        int& value(int x, int y) { return data[y * max_size + x]; }
        int& marker(int x, int y) { return direction[y * max_size + x]; }
    };
}

#endif /* string_dp_h */
