/*
Description:
            Given three integer arrays nums1, nums2, and nums3,
            return a distinct array containing all the values that are present in at least two out of the three arrays.
            You may return the values in any order.
Example 1:
Input: nums1 = [1,1,3,2], nums2 = [2,3], nums3 = [3]
Output: [3,2]
*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// Solution: Using unordered sets to track the presence of elements in the three arrays
// Time Complexity: O(n1 + n2 + n3) where n1, n
// 2, and n3 are the lengths of nums1, nums2, and nums3 respectively
// Space Complexity: O(n1 + n2 + n3) in the worst case if all elements are distinct
// Note: The space complexity can be reduced to O(n) where n is the number of distinct elements across the three arrays
// by using a single unordered set to track the presence of elements and a vector to store the result
// This solution assumes that the input arrays can contain duplicate values, and we only want distinct values in the output
// The output can be in any order, so we do not need to sort the result
class Solution
{
public:
    vector<int> twoOutOfThree(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3)
    {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());
        unordered_set<int> set3(nums3.begin(), nums3.end());

        unordered_set<int> resultSet;

        for (int num : set1)
        {
            if (set2.count(num) || set3.count(num))
                resultSet.insert(num);
        }

        for (int num : set2)
        {
            if (set1.count(num) || set3.count(num))
                resultSet.insert(num);
        }

        for (int num : set3)
        {
            if (set1.count(num) || set2.count(num))
                resultSet.insert(num);
        }

        return vector<int>(resultSet.begin(), resultSet.end());
    }
};