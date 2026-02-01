/*
Description: You are given an integer array nums with the following properties:
            nums.length == 2 * n.
            nums contains n + 1 unique values, n of which occur exactly once in the array.
            Exactly one element of nums is repeated n times.
            Return the element that is repeated n times.
Example 1:
        Input: nums = [1,2,3,3]
Output: 3

Example 2:
        Input: nums = [2,1,2,5,3,2]

Constraints:
            2 <= n <= 5000
            nums.length == 2 * n
            0 <= nums[i] <= 10^4
            nums contains n + 1 unique elements and one of them is repeated exactly n times.
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

// Solution 1:
/*
Time complexity: O(n)
space complexity: O(n)
*/
class Solution
{
public:
    int repeatedNTimes(vector<int> &nums)
    {
        unordered_set<int> st;
        int repeat = -1;
        for (int x : nums)
        {
            if (st.count(x))
            {
                repeat = x;
                break;
            }
            st.insert(x);
        }
        return repeat;
    }
};

// Solution 2:
/*
Approach : first the sort whole array then find duplicate element
Time complexity: O(n)
space complexity: O(1)
*/

class Solution
{
public:
    int repeatedNTimes(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int repeated = -1;
        int i = 0;
        while (i < nums.size())
        {
            if (nums[i] == nums[i + 1])
            {
                repeated = nums[i];
                break;
            }
            i++;
        }
        return repeated;
    }
};