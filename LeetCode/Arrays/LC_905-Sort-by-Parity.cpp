#include <bits/stdc++.h>
using namespace std;
// Solution 1;
class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &nums)
    {
        // zero as even at begining of array
        int n = nums.size();
        int beg = 0; // pointer that points at the beginning
        for (int move = 0; move < n; move++)
        {
            if (nums[move] % 2 == 0)
            {
                swap(nums[beg], nums[move]);
                beg++;
            }
        }
        return nums;
    }
};
// Solution 2:
class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &nums)
    {
        // zero as even at begining of array
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left < right)
        {
            if ((nums[left] & 1) == 1)
            {
                swap(nums[left], nums[right]);
                right--;
            }
            else
                left++;
        }
        return nums;
    }
};