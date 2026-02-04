#include <iostream>
using namespace std;

// Solution 1:
class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        size_t pos = haystack.find(needle);
        return pos;
    }
};