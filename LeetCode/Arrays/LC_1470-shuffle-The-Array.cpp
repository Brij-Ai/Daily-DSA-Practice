/*
Description: Given the array nums consisting of 2n elements in the form [x1,x2,...,xn,y1,y2,...,yn].

Return the array in the form [x1,y1,x2,y2,...,xn,yn].

Constraints:

            1 <= n <= 500
            nums.length == 2n
            1 <= nums[i] <= 10^3
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> shuffle(vector<int> &nums, int n)
    {
        int size = 2 * n;
        // vector<int>ans(size);
        for (int i = 1; i < n; i++)
        {
            swap(nums[i], nums[n + i - 1]);
        }
        return nums;
    }
};
