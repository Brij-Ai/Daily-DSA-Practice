// Description: https://leetcode.com/problems/find-if-digit-game-can-be-won/description/
/*
Constraints:
1 <= nums.length <= 100
1 <= nums[i] <= 99
*/
#include <vector>
using namespace std;

// Solution 1: Time complexity O(n) and space complexity O(1);
class Solution
{
public:
    bool canAliceWin(vector<int> &nums)
    {
        int sum[2] = {};
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < 10)
                sum[0] += nums[i];
            else
                sum[1] += nums[i];
        }
        if (sum[0] != sum[1])
            return true;
        else
            return false;
    }
};