/*
Description: https://leetcode.com/problems/sort-the-people/
Constarints:
1 <= names.length <= 100
names.length == heights.length
1 <= names[i].length <= 20
names[i] consists of lower and upper case English letters.
1 <= heights[i] <= 10^5

Example:
Input: names = ["Mary","John","Emma"], heights = [180,165,170]
Output: ["Mary","Emma","John"]
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Solution 1: Time complexity O(n^2) and space complexity O(1);
class Solution
{
public:
    vector<string> sortPeople(vector<string> &names, vector<int> &heights)
    {
        int i = 0;
        while (i < names.size())
        {
            int j = i + 1;
            while (j < names.size())
            {
                if (heights[i] < heights[j])
                {
                    swap(heights[i], heights[j]);
                    swap(names[i], names[j]);
                }
                j++;
            }
            i++;
        }
        return names;
    }
};

// Solution 2: Time complexity O(nlogn) and space complexity O(n);
class Solution
{
public:
    vector<string> sortPeople(vector<string> &names, vector<int> &heights)
    {
        int n = names.size();
        vector<pair<int, string>> people(n);
        for (int i = 0; i < n; i++)
            people[i] = {heights[i], names[i]};
        sort(people.rbegin(), people.rend());
        vector<string> ans(n);
        for (int i = 0; i < n; i++)
            ans[i] = people[i].second;
        return ans;
    }
};