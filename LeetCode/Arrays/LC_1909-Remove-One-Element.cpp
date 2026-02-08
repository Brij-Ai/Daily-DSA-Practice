/*
Descirption: Given a 0-indexed integer array nums, return true if it can be made strictly increasing after removing exactly one element, or false otherwise.
            If the array is already strictly increasing, return true.
            The array nums is strictly increasing if nums[i - 1] < nums[i] for each index (1 <= i < nums.length).
*/

#include <iostream>
#include <vector>
using namespace std;
// Solution 1: O(n) time, O(1) space
class Solution
{
public:
    bool canBeIncreasing(vector<int> &nums)
    {
        int n = nums.size();
        int count = 0; // number of violations

        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] >= nums[i + 1])
            {
                count++;

                // More than one violation → not possible
                if (count > 1)
                    return false;

                // Decide which element to "remove"
                if (i > 0 && nums[i - 1] >= nums[i + 1])
                {
                    nums[i + 1] = nums[i];
                }
                // else logically remove nums[i]
            }
        }
        return true;
    }
};
