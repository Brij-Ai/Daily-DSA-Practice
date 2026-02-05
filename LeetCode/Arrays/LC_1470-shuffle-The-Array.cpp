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
/*
Time complexity: O(n)
Space complexity: O(1)
*/
class Solution
{
public:
    vector<int> shuffle(vector<int> &nums, int n)
    {
        int size = 2 * n;
        vector<int> ans(size);
        for (int i = 0; i < n; i++)
        {
            ans[2 * i] = nums[i];
            ans[2 * i + 1] = nums[n + i];
        }
        return ans;
    }
};

/*
Time complexity: O(n)
Space complexity: O(n)
*/
class Solution
{
public:
    vector<int> shuffle(vector<int> &nums, int n)
    {
        vector<int> ans(2 * n);
        for (int i = 0; i < 2 * n; i++)
        {
            if (i % 2 == 0)
            {
                ans[i] = nums[i / 2];
            }
            else
            {
                ans[i] = nums[n + i / 2];
            }
        }
        return ans;
    }
};
