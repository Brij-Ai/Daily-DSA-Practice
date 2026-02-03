/*
Description:You are given an array arr[] of size n - 1 that contains distinct integers in the range from 1 to n (inclusive).
            This array represents a permutation of the integers from 1 to n with one element missing.
            Your task is to identify and return the missing element
Input: arr[] = [1, 2, 3, 5]
Output: 4
Explanation: All the numbers from 1 to 5 are present except 4.
*/
#include <bits/stdc++.h>
using namespace std;
// Solution 1:
class Solution
{
public:
    int missingNum(vector<int> &arr)
    {
        int n = arr.size() + 1;
        int xor1 = 0, xor2 = 0;

        for (int i = 1; i <= n; i++)
            xor1 ^= i;

        for (int i = 0; i < n - 1; i++)
            xor2 ^= arr[i];

        return xor1 ^ xor2;
    }
};

// Solution 2:
class Solution
{
public:
    int missingNum(vector<int> &arr)
    {
        long long n = arr.size() + 1;
        long long sum = n * (n + 1) / 2;

        for (int i = 0; i < n - 1; i++)
        {
            sum -= arr[i];
        }

        return (int)sum;
    }
};
