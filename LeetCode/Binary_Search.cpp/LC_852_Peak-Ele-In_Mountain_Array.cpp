// Description: https://leetcode.com/problems/peak-index-in-a-mountain-array/
#include <vector>
using namespace std;
// Linear Search
class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        for (int i = 1; i < arr.size() - 1; i++)
        {
            if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
            {
                return i;
            }
        }
        return -1; // This line should never be reached since the input is guaranteed to be a mountain array
    }
};

// Binary Search
class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int left = 0, right = arr.size() - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (arr[mid] < arr[mid + 1])
            {
                left = mid + 1; // Move right
            }
            else
            {
                right = mid; // Move left
            }
        }
        return left; // or right, both are the same at this point
    }
};