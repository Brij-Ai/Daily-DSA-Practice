/*
Description:Given an array nums of integers,
            return how many of them contain an even number of digits.

Example 1:
            Input: nums = [12,345,2,6,7896]
            Output: 2
*/

#include <bits/stdc++.h>
using namespace std;
// Solution 1:
// Time complexity : O(nlogn)

class Solution
{
public:
    int findNumbers(vector<int> &nums)
    {
        int n = nums.size();
        int ans = 0;
        for (int x : nums)
        {
            int count = 0;
            int temp = x;
            while (temp > 0)
            {
                temp /= 10;
                count++;
            }
            if (count % 2 == 0)
            {
                ans++;
            }
        }
        return ans;
    }
};

// Solution 2:
//  Time complexity : O(n);

class Solution
{
public:
    int findNumbers(vector<int> &nums)
    {
        int ans = 0;
        for (int x : nums)
        {
            if ((x >= 10 && x <= 99) || (x >= 1000 && x <= 9999) || x == 100000)
            {
                ans++;
            }
        }
        return ans;
    }
};

// Solution 3:

// ALgo : digits=⌊log10​(n)⌋+1
class Solution
{
public:
    int findNumbers(vector<int> &nums)
    {
        int ans = 0;

        for (int num : nums)
        {
            int digits = floor(log10(num)) + 1;
            if (digits % 2 == 0)
                ans++;
        }

        return ans;
    }
};
