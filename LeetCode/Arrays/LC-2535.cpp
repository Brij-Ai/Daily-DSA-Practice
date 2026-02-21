/*
Description:You are given a positive integer array nums.
            The element sum is the sum of all the elements in nums.
            The digit sum is the sum of all the digits (not necessarily distinct) that appear in nums.
            Return the absolute difference between the element sum and digit sum of nums
*/

#include <vector>
#include <cmath>
using namespace std;

// Solution 1:
class Solution
{
public:
    int differenceOfSum(vector<int> &nums)
    {
        int sum = 0;
        int digitSum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            int temp = nums[i];
            while (temp > 0)
            {
                digitSum += temp % 10;
                temp /= 10;
            }
        }
        return abs(sum - digitSum);
    }
};