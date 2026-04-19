// Problem Link : https://leetcode.com/problems/smallest-stable-index-ii/description/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int firstStableIndex(vector<int> &nums, int k)
    {
        int n = nums.size();
        // stores the minimum subarray min from the back side
        vector<int> postMin(n);
        int currentMinBack = nums[n - 1];

        // Precalculating min elements in nums from the back side
        for (int i = n - 1; i >= 0; i--)
        {
            currentMinBack = min(currentMinBack, nums[i]);
            postMin[i] = currentMinBack;
        }

        // finding the stable idx
        int stableIdx = -1;
        int preMax = nums[0];
        for (int i = 0; i < nums.size(); i++)
        {
            // updating our maximum at current idx
            preMax = max(preMax, nums[i]);
            // if stisfies then breaking here
            if (preMax - postMin[i] <= k)
            {
                stableIdx = i;
                break;
            }
        }

        return stableIdx;
    }
};

// Solution 2:
class Solution
{
public:
    int firstStableIndex(vector<int> &nums, int k)
    {
        int n = nums.size();

        // Step 1: Suffix minimum array
        vector<int> suffixMin(n);
        int minFromRight = nums[n - 1];

        for (int i = n - 1; i >= 0; i--)
        {
            minFromRight = min(minFromRight, nums[i]);
            suffixMin[i] = minFromRight;
        }

        // Step 2: Prefix max + condition check
        int prefixMax = nums[0];

        for (int i = 0; i < n; i++)
        {
            prefixMax = max(prefixMax, nums[i]);

            if (prefixMax - suffixMin[i] <= k)
            {
                return i;
            }
        }

        return -1;
    }
};