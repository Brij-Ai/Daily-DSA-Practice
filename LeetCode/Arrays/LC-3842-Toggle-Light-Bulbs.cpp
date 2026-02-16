/*
Description:You are given an array bulbs of integers between 1 and 100.
            There are 100 light bulbs numbered from 1 to 100. All of them are switched off initially.
            For each element bulbs[i] in the array bulbs:
            If the bulbs[i]th light bulb is currently off, switch it on.
            Otherwise, switch it off.
Return the list of integers denoting the light bulbs that are on in the end, sorted in ascending order. If no bulb is on, return an empty list.
Example 1:
Input: bulbs = [1,2,3,2]
Output: [1,3]
Explanation:
Initially, all the bulbs are off.
After the first operation, the 1st bulb is switched on. Status of bulbs: [on, off, off, off, ..., off]
After the second operation, the 2nd bulb is switched on. Status of bulbs: [on, on, off, off, ..., off]
After the third operation, the 3rd bulb is switched on. Status of bulbs: [on, on, on, off, ..., off]
After the fourth operation, the 2nd bulb is switched off. Status of bulbs: [on, off, on, off, ..., off]
*/

#include <vector>
#include <algorithm>
using namespace std;

// Solution 1: Sorting then finding
// Time complexity O(nlog) for sorting + O(n) linear search and Space complexity O(n) for storing the result
class Solution
{
public:
    vector<int> toggleLightBulbs(vector<int> &bulbs)
    {
        // vector<bool>toggle(bulbs.size(),false);
        vector<int> ans;
        sort(bulbs.begin(), bulbs.end());
        int cur = 0, move = 0;
        int cnt = 0;
        if (bulbs.size() == 1)
            return {bulbs[0]};
        while (move < bulbs.size())
        {
            if (bulbs[cur] == bulbs[move])
            {
                cnt++;
                move++;
            }
            else
            {
                if (cnt % 2 != 0)
                    ans.push_back(bulbs[cur]);
                cur = move;
                cnt = 0;
            }
        }
        if (cnt % 2 != 0)
            ans.push_back(bulbs[cur]);
        return ans;
    }
};

// Solution 2: frequency array
// Time complexity O(n) and Space complexity O(1) since the size of the frequency
// array is fixed at 100
class Solution
{
public:
    vector<int> toggleLightBulbs(vector<int> &bulbs)
    {
        if (bulbs.size() == 1)
            return {bulbs[0]};
        vector<int> count(101, 0);
        vector<int> ans;
        for (int i = 0; i < bulbs.size(); i++)
        {
            count[bulbs[i]]++;
        }
        for (int i = 1; i < 101; i++)
        {
            if (count[i] % 2 != 0)
                ans.push_back(i);
        }
        return ans;
    }
};