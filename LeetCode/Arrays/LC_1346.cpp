/*
    1346. Check If N and Its Double Exist
    Description: Given an array arr of integers, check if there exist two indices i and j such that :
    rules:
        i != j
        0 <= i, j < arr.length
        arr[i] == 2 * arr[j]

Example 1:

        Input: arr = [10,2,5,3]
        Output: true
        Explanation: For i = 0 and j = 2, arr[i] == 10 == 2 * 5 == 2 * arr[j]
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool checkIfExist(vector<int> &arr)
    {
        // int temp = -1;
        int n = arr.size();
        int i = 0;
        while (i < n)
        {
            if (arr[i] % 2 == 0)
            {
                int j = 0;
                while (j < n)
                {
                    if (j != i && arr[j] == arr[i] / 2)
                        return true;
                    j++;
                }
            }
            i++;
        }
        return false;
    }
};

// Solution 2:

class Solution
{
public:
    bool checkIfExist(vector<int> &arr)
    {
        int temp = -1;
        int n = arr.size();
        int i = 0;
        while (i < n)
        {
            if (arr[i] % 2 == 0)
            {
                int j = 0;
                while (j < n)
                {
                    if (j != i && 2 * arr[j] == arr[i])
                        return true;
                    j++;
                }
            }
            i++;
        }
        return false;
    }
};