/*
Description: How many numbers are smaller than the current number?
Constraints:
2 <= nums.length <= 500
0 <= nums[i] <= 100
Example:
Input: nums = [8,1,2,2,3]
Output: [4,0,1,1,3]
*/

#include <iostream>
#include <vector>
using namespace std;

// Refer solution 2 of LC-1365-HowManyNuberAreSmallerThan.cpp for better understanding.
// Solution 1: Time complexity O(n^2) and space complexity O(1);
class Solution
{
public:
    vector<int> smallerNumbersThanCurrent(vector<int> &nums)
    {
        int n = nums.size();
        int i = 0;
        vector<int> ans;
        while (i < n)
        {
            int j = 0;
            int cnt = 0;
            while (j < n)
                if (nums[i] > nums[j++])
                    cnt++;
            ans.push_back(cnt);
            i++;
        }
        return ans;
    }
};

// Solution 2: Time complexity O(n) and space complexity O(1);
class Solution
{
public:
    vector<int> smallerNumbersThanCurrent(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> cnt(101, 0);
        for (int i = 0; i < n; i++)
            cnt[nums[i]]++;
        for (int i = 1; i <= 100; i++)
            cnt[i] += cnt[i - 1];
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
            ans[i] = nums[i] == 0 ? 0 : cnt[nums[i] - 1];
        return ans;
    }
};