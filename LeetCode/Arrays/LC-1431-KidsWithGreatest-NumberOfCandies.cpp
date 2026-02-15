// Description: https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/
#include <vector>
using namespace std;

// Solution 1: Time complexity O(n) ,Space complexity O(n)
class Solution
{
public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
    {
        vector<bool> ans(candies.size(), false);
        int max = -1;
        for (int x : candies)
        {
            if (x > max)
                max = x;
        }
        for (int i = 0; i < candies.size(); i++)
        {
            if (candies[i] + extraCandies >= max)
                ans[i] = true;
        }
        return ans;
    }
};