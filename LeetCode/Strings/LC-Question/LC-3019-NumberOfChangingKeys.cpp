/*
Description:https://leetcode.com/problems/number-of-changing-keys/description/
*/

#include <iostream>
#include <string>
using namespace std;

// Solution 1: Time complexity O(n) and space complexity O(1);
class Solution
{
public:
    int countKeyChanges(string s)
    {
        int count = 0;
        for (int i = 1; i < s.size(); i++)
        {
            if (tolower(s[i]) != tolower(s[i - 1]))
            {
                count++;
            }
        }
        return count;
    }
};
