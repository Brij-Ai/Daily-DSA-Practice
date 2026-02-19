/*
Description:Given an array arr[] of integers and a range [low, high],
            find all the numbers within the range that are not present in the array.
            return the missing numbers in sorted order.
Example 1:
Input:
arr[] = [10, 12, 11, 15], low = 10, high = 15
Output: [13, 14]
*/

#include <bits/stdc++.h>
using namespace std;

// Solution using unordered_set to find missing numbers in the given range
// Time Complexity: O(n + m) where n is the size of the input array and m is the size of the range [low, high]
class Solution
{
public:
    vector<int> missinRange(vector<int> &arr, int low, int high)
    {
        unordered_set<int> freq(arr.size());

        for (int x : arr)
        {
            freq.insert(x);
        }

        vector<int> ans;
        while (low <= high)
        {
            if (!freq.count(low))
                ans.push_back(low);
            low++;
        }
        return ans;
    }
};
vector<int> findMissing(int arr[], int low, int high)
{
    vector<int> missingNumbers;
    unordered_set<int> presentNumbers(arr, arr + sizeof(arr) / sizeof(arr[0]));

    for (int num = low; num <= high; num++)
    {
        if (presentNumbers.find(num) == presentNumbers.end())
        {
            missingNumbers.push_back(num);
        }
    }

    return missingNumbers;
}

int main()
{
    int arr[] = {10, 12, 11, 15};
    int low = 10;
    int high = 15;

    vector<int> missingNumbers = findMissing(arr, low, high);

    cout << "Missing numbers in the range [" << low << ", " << high << "] are: ";
    for (int num : missingNumbers)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}