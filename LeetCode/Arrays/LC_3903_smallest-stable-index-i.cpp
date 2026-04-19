// problem:https://leetcode.com/problems/smallest-stable-index-i/description/
#include <vector>
using namespace std;

// Solution 1:
class Solution
{
public:
    int firstStableIndex(vector<int> &nums, int k)
    {
        int stableIdx = -1;
        int maxCurrent = nums[0];
        for (int i = 0; i < nums.size(); i++)
        {

            if (nums[i] > maxCurrent)
                maxCurrent = nums[i];
            int minCurrent = nums[i];
            for (int j = i; j < nums.size(); j++)
            {
                minCurrent = min(nums[j], minCurrent);
            }
            if (maxCurrent - minCurrent <= k)
            {
                stableIdx = i;
                break;
            }
        }

        return stableIdx;
    }
};

// Solution 2 : Optimized
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