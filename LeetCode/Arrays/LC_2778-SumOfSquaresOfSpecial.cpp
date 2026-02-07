/*
Description: 2778. Sum of Squares of Special Elements
            An element nums[i] of nums is called special if i divides n, i.e. n % i == 0.
            Return the sum of the squares of all special elements of nums.

Example 1:
            Input: nums = [1,2,3,4]
Output: 21
Explanation: There are exactly 3 special elements in nums: nums[1] since 1 divides 4, nums[2] since 2 divides 4, and nums[4] since 4 divides 4.
            Hence, the sum of the squares of all special elements of nums is nums[1] _ nums[1] + nums[2] _ nums[2] + nums[4] _ nums[4] = 1 _ 1 + 2 _ 2 + 4 _ 4 = 21.
*/
#include <iostream>
#include <vector>
using namespace std;
// Solution 1:
class Solution
{
public:
      int sumOfSquares(vector<int> &nums)
      {
            int n = nums.size();
            int sumOfSpecial = 0;
            for (int i = 0; i < n; i++)
            {
                  if (n % (i + 1) == 0)
                        sumOfSpecial += nums[i] * nums[i];
            }
            return sumOfSpecial;
      }
};

// Solution 2:
class Solution
{
public:
      int sumOfSquares(vector<int> &nums)
      {
            int n = nums.size();
            int sumOfSpecial = 0;
            for (int i = 0; i < n; i++)
            {
                  int temp = i + 1;
                  if (n % temp == 0)
                  {
                        sumOfSpecial += nums[i] * nums[i];
                  }
            }
            return sumOfSpecial;
      }
};
