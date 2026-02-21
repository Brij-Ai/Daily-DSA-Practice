#include <bits/stdc++.h>
using namespace std;
// Solution 1: Time complexity O(n) and space complexity O(1);
class Solution
{
public:
    int smallestEqual(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (i % 10 == nums[i])
                return i;
        }
        return -1;
    }
};

class Solution
{
public:
    int smallestEqual(vector<int> &nums)
    {
        int idx = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i % 10 == nums[i])
            {
                idx = i;
                break;
            }
        }
        return idx;
    }
};