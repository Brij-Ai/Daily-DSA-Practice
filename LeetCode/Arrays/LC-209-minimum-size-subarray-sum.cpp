// 🧩 Problem
// Given an array of positive integers `nums` and a positive integer `target`, return the **minimal length** of a subarray whose sum is **greater than or equal to `target`**.
// If there is no such subarray, return `0`.

#include <iostream>
#include <vector>
using namespace std;

// Time complexity : O(n) and Space complexity : O(1)
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int currLength = 0, windowSize = 0;
        long long subArrSum = 0;
        int n = nums.size();

        // Expand initial window until sum >= target
        for (int x : nums)
        {
            subArrSum += x;
            windowSize++;
            currLength++;
            if (subArrSum >= target)
                break;
        }

        // If total sum < target, return 0
        if (subArrSum < target)
            return 0;

        int minLength = currLength;

        for (int i = 0; i < n; i++)
        {
            // Shrink window from left
            subArrSum -= nums[i];
            currLength--;

            // Expand window if needed
            if (windowSize < n && subArrSum < target)
            {
                subArrSum += nums[windowSize];
                currLength++;
                windowSize++;
            }

            // Update minimum length
            if (subArrSum >= target)
            {
                minLength = min(minLength, currLength);
            }
        }

        return minLength;
    }
};