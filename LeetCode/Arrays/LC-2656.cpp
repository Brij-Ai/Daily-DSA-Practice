/*
Description: https://leetcode.com/problems/maximum-sum-with-exactly-k-elements/
About: You are given a 0-indexed integer array nums and an integer k.
        Your task is to perform the following operation exactly k times in order to maximize your score:
        Select an element m from nums.
        1.Remove the selected element m from the array.
        2.Add a new element with a value of m + 1 to the array.
        3.Increase your score by m.
        Return the maximum score you can achieve after performing the operation exactly k times
*/

#include <vector>
using namespace std;

// TIme complexity: O(n)
class Solution
{
public:
    int maximizeSum(vector<int> &nums, int k)
    {

        int max = 0;
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] > max)
                max = nums[i];

        int sum = 0;
        while (k > 0)
        {
            sum += max++;
            k--;
        }
        return sum;
    }
};