/*
Description : Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.
*/

#include <bits/stdc++.h>
using namespace std;

// Solution 1:
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        k = k % n; // Important
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};

// Solution 2:
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        k = k % n;
        vector<int> temp(n);
        for (int i = 0; i < n; i++)
        {
            temp[(i + k) % n] = nums[i];
        }
        nums = temp;
    }
};