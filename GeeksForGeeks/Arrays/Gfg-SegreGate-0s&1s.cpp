// User function template for C++
#include <bits/stdc++.h>
using namespace std;

// Solution 1: Time complexity O(n) and space complexity O(1);
// using two pointer approach
class Solution
{
public:
    void segregate0and1(vector<int> &arr)
    {
        int st = 0;
        int end = arr.size() - 1;
        while (st < end)
        {
            if (arr[st] == 1)
            {
                if (arr[end] == 0)
                {
                    swap(arr[st], arr[end]);
                    st++;
                }
                else
                    end--;
            }
            else
                st++;
        }
    }
};

// Solution 2: Time complexity O(nlogn) and space complexity O(1);
// using sort function
class Solution2
{
public:
    void segregate0and1(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
    }
};