/*
Description: Given an array of integers arr, a lucky integer is an integer that has a frequency in the array equal to its value.
            Return the largest lucky integer in the array. If there is no lucky integer return -1.
*/
#include <iostream>
#include <vector>
using namespace std;

// Solution:
class Solution
{
public:
    int findLucky(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> freq(500 + 1, 0);
        for (int i = 0; i < n; i++)
        {
            freq[arr[i]] = freq[arr[i]] + 1;
        }
        int lucky = 0;
        for (int i = 1; i <= 500; i++)
        {
            if (freq[i] == i && freq[i] > lucky)
                lucky = freq[i];
        }
        return lucky == 0 ? -1 : lucky;
    }
};

// Solution
class Solution
{
public:
    int findLucky(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> freq(500 + 1, 0);
        for (int i = 0; i < n; i++)
        {
            freq[arr[i]] = freq[arr[i]] + 1;
        }
        int lucky = 0;
        for (int i = 1; i <= 500; i++)
        {
            if (freq[i] == i && freq[i] > lucky)
                lucky = freq[i];
        }
        return lucky == 0 ? -1 : lucky;
    }
};