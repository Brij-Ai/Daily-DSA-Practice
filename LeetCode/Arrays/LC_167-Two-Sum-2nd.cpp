/*
Description: Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order,
            find two numbers such that they add up to a specific target number.
            Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.
            Return the indices of the two numbers,
            index1 and index2, added by one as an integer array [index1, index2] of length 2.
            The tests are generated such that there is exactly one solution. You may not use the same element twice.
            Your solution must use only constant extra space
*/

#include <iostream>
#include <vector>
using namespace std;

// Solution 1:
class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int n = numbers.size();
        int start = 0, end = n - 1;
        while (start < end)
        {
            if (numbers[start] + numbers[end] == target)
            {
                break;
            }
            else if (numbers[start] + numbers[end] < target)
            {
                start++;
            }
            else
            {
                end--;
            }
        }
        return {start + 1, end + 1};
    }
};