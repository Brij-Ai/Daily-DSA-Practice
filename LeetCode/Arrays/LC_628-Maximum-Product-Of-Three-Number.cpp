/*
Description: Given an integer array nums,
            find three numbers whose product is maximum and return the maximum product.

Example 1:
            Input: nums = [1,2,3]
            Output: 6

Example 2:
            Input: nums = [1,2,3,4]
            Output: 24
*/

/*
    Approach:
                Track the top 3 max values: max1, max2, max3
                Track the bottom 2 min values: min1, min2
                Return the maximum of:
                max1 * max2 * max3
                min1 * min2 * max1 (handles negative * negative * positive)

    Complexity:
                Time complexity: O(n)
                Space complexity: O(1)
*/
#include <bits/stdc++.h>
using namespace std;

// Solution 1: Optimal
class Solution
{
public:
    int maximumProduct(vector<int> &nums)
    {
        int n = nums.size();
        int max1 = -1001;
        int max2 = max1, max3 = max1;
        int min1 = 1001, min2 = 1001;
        for (int x : nums)
        {
            if (x > max1)
            {
                max3 = max2;
                max2 = max1;
                max1 = x;
            }
            else if (x > max2)
            {
                max3 = max2;
                max2 = x;
            }
            else if (x > max3)
            {
                max3 = x;
            }
            if (x < min1)
            {
                min2 = min1;
                min1 = x;
            }
            else if (x < min2)
            {
                min2 = x;
            }
        }
        long long prod1 = 1LL * max1 * max2 * max3;
        long long prod2 = 1LL * min1 * min2 * max1;
        return max(prod1, prod2);
    }
};
// Solution 2: Not a optimal
/*
    Complexity:
                Time complexity: O(nlogn)
                Space complexity: O(1)
*/
class Solution
{
public:
    int maximumProduct(vector<int> &nums)
    {
        int n = nums.size();
        int max1, max2, max3;
        int min1, min2;
        sort(nums.begin(), nums.end());
        min1 = nums[0];
        min2 = nums[1];
        max1 = nums[n - 1];
        max2 = nums[n - 2];
        max3 = nums[n - 3];
        long long prod1 = 1LL * max1 * max2 * max3;
        long long prod2 = 1LL * min1 * min2 * max1;
        return max(prod1, prod2);
    }
};