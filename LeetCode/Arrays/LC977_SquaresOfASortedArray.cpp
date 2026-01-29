/*Description:Given an integer array nums sorted in non-decreasing order,
  return an array of the squares of each number sorted in non-decreasing order.
  Difficulty: Easy
  Topics: Array,Two Pointer,Sorting
  Input: nums = [-4,-1,0,3,10]
  Output: [0,1,9,16,100]
  I/P : nums = [-5,-3,-2,-1]   O/P nums = [1,4,9,25]
  After squaring, the array becomes [16,1,0,9,100].
  After sorting, it becomes [0,1,9,16,100].
 */

/*
  Approach 1. Squaring each element , then sorting it
  Time complexity: O(n) + O(nlogn) [O(nlogn) for sorting]
  Space complexity: O(1)
*/

/*
  Approach 2. Using Two pointer (maintining Two pointer)
  Time complexity: O(n)
  Space complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Solution 1.
class Solution
{
public:
  vector<int> sortedSquares(vector<int> &nums)
  {
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
      nums[i] *= nums[i];
    }
    sort(nums.begin(), nums.end());
    return nums;
  }
};

// Solution 2.Two pointer
