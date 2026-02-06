/*
Description: A school is trying to take an annual photo of all the students.
            The students are asked to stand in a single file line in non-decreasing order by height.
            Let this ordering be represented by the integer array expected where expected[i] is the expected height of the ith student in line.
            You are given an integer array heights representing the current order that the students are standing in.
            Each heights[i] is the height of the ith student in line (0-indexed).

            Return the number of indices where heights[i] != expected[i].
*/

#include <bits/stdc++.h>
using namespace std;

// Solution 1:
// Brute Force
class Solution
{
public:
    int heightChecker(vector<int> &nums)
    {
        vector<int> ex = nums;
        // ex = nums;
        sort(ex.begin(), ex.end());
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != ex[i])
                count++;
        }
        return count;
    }
};