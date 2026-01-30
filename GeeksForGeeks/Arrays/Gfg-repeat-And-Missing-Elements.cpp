// Description: Given an unsorted array arr[] of size n,
// containing elements from the range 1 to n, it is known that one number in this range is missing, and another number occurs twice in the array,
// find both the duplicate number and the missing number.
// Approach 1.
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    vector<int> findTwoElement(vector<int> &nums)
    {
        int n = nums.size();
        int missing = -1, dup = -1;
        for (int i = 0; i < n; i++)
        {
            if (nums[abs(nums[i]) - 1] < 0)
            {
                dup = abs(nums[i]);
            }
            else
            {
                nums[abs(nums[i]) - 1] *= (-1);
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0)
            {
                missing = (i + 1);
                break;
            }
        }
        return {dup, missing};
    }
};
