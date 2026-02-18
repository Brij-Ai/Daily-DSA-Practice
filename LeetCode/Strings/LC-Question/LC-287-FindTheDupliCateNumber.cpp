/*
Note : You must solve the problem without modifying the array nums and using only constant extra space.
        Can you solve the problem in linear runtime complexity?

Description: Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
There is only one repeated number in nums, return this repeated number.
Example 1:
Input: nums = [1,3,4,2,2]
Output: 2
Example 2:
Input: nums = [3,1,3,4,2]
Output: 3
Example 3:
Input: nums = [1,1]
Output: 1

// Link : https://leetcode.com/problems/find-the-duplicate-number/solutions/1892921/9-approaches-count-hash-in-place-marked-n2arx/
*/
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// Solution 1: Using a Hash Set to find the duplicate number
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        unordered_set<int> seen; // Set to store seen numbers

        for (int num : nums)
        {
            // If the number is already in the set, it's the duplicate
            if (seen.count(num))
            {
                return num; // Return the duplicate number
            }
            seen.insert(num); // Add the number to the set
        }

        return -1; // Return -1 if no duplicate is found (though problem guarantees one duplicate)
    }
};

// Solution 2: Using the Tortoise and Hare (Floyd's Cycle Detection) algorithm
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int tortoise = nums[0]; // Start of the cycle
        int hare = nums[0];     // Start of the cycle

        // First phase: Finding the intersection point in the cycle
        do
        {
            tortoise = nums[tortoise]; // Move tortoise by 1 step
            hare = nums[nums[hare]];   // Move hare by 2 steps
        } while (tortoise != hare);

        // Second phase: Finding the entrance to the cycle
        tortoise = nums[0]; // Start from the beginning

        while (tortoise != hare)
        {
            tortoise = nums[tortoise]; // Move tortoise by 1 step
            hare = nums[hare];         // Move hare by 1 step
        }

        return tortoise; // The duplicate number is the entrance to the cycle
    }
};

// Solution 3: Using Negative Marking to find the duplicate number
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {

        for (int i = 0; i < nums.size(); i++)
        {
            int index = abs(nums[i]) - 1; // Get the index (subtract 1 because array is 0-indexed)
            if (nums[index] < 0)
            {
                return abs(nums[i]); // If the value at index is negative, it's a duplicate
            }
            nums[index] = -nums[index]; // Mark the value at index as visited by negating it
        }

        return -1; // Return -1 if no duplicate is found (though problem guarantees one duplicate)
    }
};

// Solution 4: Frequency Count using an Array to find the duplicate number
// Time Complexity: O(n), Space Complexity: O(n)
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        vector<int> freq(nums.size(), 0);
        int i = 0;
        for (; i < nums.size(); i++)
        {
            if (freq[nums[i] - 1] == 0)
                freq[nums[i] - 1] = -1;
            else
                break;
        }
        return nums[i];
    }
};