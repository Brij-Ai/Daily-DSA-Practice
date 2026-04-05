// Link : https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/

#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int maxOnes = 0, countOnes = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
                countOnes++;

            if (nums[i] == 0)
            {
                int right = i + 1, left = i - 1;
                int leftCount = 0, rightCount = 0;

                // Left window forming of ones
                while (right < nums.size() and nums[right] != 0)
                    right++, rightCount++;
                // right window forming of ones
                while (left >= 0 and nums[left] != 0)
                    left--, leftCount++;
                // Max window size which contains max ones and only one zero
                if (maxOnes < leftCount + rightCount)
                    maxOnes = leftCount + rightCount;
            }
        }
        // condtion when no zeros in arrays
        if (countOnes == nums.size())
            return countOnes - 1;

        return maxOnes;
    }
};