/*
Description: Given an array of integers arr,
return true if the number of occurrences of each value in the array is unique or false otherwise.

Input: arr = [1,2,2,1,1,3]
Output: true
Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        vector<int> ca(2001);
        for (int i : arr)
        {
            ca[i + 1000]++;
        }
        sort(ca.begin(), ca.end());
        for (int i = 0; i < 2000; i++)
        {
            if (ca[i] != 0 && ca[i] == ca[i + 1])
            {
                return false;
            }
        }
        return true;
    }
};

// Approach 2.
/*
Time complexity: O(nlogn)+O(k) //sorting then freqency count
Space complexity: O(n) No extra space
*/
// Own logic
class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        unordered_set<int> st;
        sort(arr.begin(), arr.end());
        int count = 0;
        int curr = arr[0];
        for (int i = 0; i < arr.size(); i++)
        {
            if (curr == arr[i])
            {
                count++;
            }
            else if (st.count(count))
                return false;
            else
            {
                st.insert(count);
                count = 1;
                curr = arr[i];
            }
        }
        if (st.count(count))
            return false;
        else
            st.insert(count);
        return true;
    }
};

// Approach Most optimal
// Time: O(n)
// Space: O(n)
class Approach
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        unordered_map<int, int> freq;
        for (int x : arr)
            freq[x]++;

        unordered_set<int> st;
        for (auto &p : freq)
        {
            if (st.count(p.second))
                return false;
            st.insert(p.second);
        }
        return true;
    }
};
