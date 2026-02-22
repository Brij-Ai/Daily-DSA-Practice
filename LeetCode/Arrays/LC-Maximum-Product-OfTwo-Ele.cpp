/*
Description:Given an integer array nums, find the maximum product of two distinct elements in the array.
The maximum product of two distinct elements is the largest product that can be obtained from multiplying two different elements in the array.
Return the maximum product of two distinct elements in nums.
Example 1:
Input: nums = [3,4,5,2]
Output: 20
Explanation: The maximum product can be obtained from multiplying 4 and 5, which gives us 20.
Constraints:
2 <= nums.length <= 500
1 <= nums[i] <= 10^3
*/

#include <vector>
#include <algorithm>
using namespace std;

// Solution 1: Time complexity O(nlogn) and space complexity O(1);
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return (nums[n - 1] - 1) * (nums[n - 2] - 1);
    }
};

// Solution 2: Time complexity O(n) and space complexity O(1);
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        long first = 0, sec = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > first)
            {
                sec = first;
                first = nums[i];
            }
            else if (nums[i] > sec)
                sec = nums[i];
        }
        return ((first - 1) * (sec - 1));
    }
};