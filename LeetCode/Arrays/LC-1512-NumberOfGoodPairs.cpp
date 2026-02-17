/*
Description: https://leetcode.com/problems/number-of-good-pairs/description/
Constraints:
1 <= nums.length <= 100
1 <= nums[i] <= 100
Example:
Input: nums = [1,2,3,1,1,3]
Output: 4
*/
// Refer solution 2;

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Solution 1: Time complexity O(n+nLogn) and space complexity O(1);
class Solution
{
public:
    int numIdenticalPairs(vector<int> &nums)
    {
        if (nums.size() == 1)
            return 0;
        sort(nums.begin(), nums.end());
        int curr = 0, move = 1, cnt = 0;
        while (move < nums.size())
        {
            if (nums[curr] == nums[move])
                cnt++;
            else
                curr = move++;
        }
        return cnt;
    }
};

// Solution 2: Time complexity O(n) and space complexity O(1);
class Solution
{
public:
    int numIdenticalPairs(vector<int> &nums)
    {
        vector<int> cnt(101, 0);
        for (int i = 0; i < nums.size(); i++)
            cnt[nums[i]]++;
        int ans = 0;
        for (int i = 1; i <= 100; i++)
            ans += cnt[i] * (cnt[i] - 1) / 2;
        return ans;
    }
};