/*
Description: Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.
            Return the kth positive integer that is missing from this array.
Example 1:
Input: arr = [2,3,4,7,11], k = 5
Output: 9
Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.
*/
#include <iostream>
#include <vector>
using namespace std;

// Solution : O(logn)
// using binary search
class Solution
{
public:
    int kthMissing(vector<int> &nums, int k)
    {
        int right = nums.size();
        int left = 0;

        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] - mid - 1 < k)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        return left + k;
    }
};

// Solution 2: O(n)
// Linear search