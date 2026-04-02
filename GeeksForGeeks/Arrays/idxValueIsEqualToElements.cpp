// Refrence Link : https://www.geeksforgeeks.org/problems/value-equal-to-index-value1330/1

// Description: Given an array of integers,
// find all elements which are equal to their index value. (Consider 1-based indexing)

#include <iostream>
#include <vector>
using namespace std;

vector<int> valueEqualToIndex(vector<int> &arr)
{
    vector<int> result;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == i + 1)
        {
            result.push_back(arr[i]);
        }
    }
    return result;
}
// time complexity: O(n)
// space complexity: O(n) in worst case when all elements are equal to their index + 1, otherwise O(1) if no elements match the condition.
// Test case:
int main()
{
    vector<int> arr = {15, 2, 45, 12, 7};
    vector<int> result = valueEqualToIndex(arr);

    cout << "Elements equal to their index + 1: ";
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}