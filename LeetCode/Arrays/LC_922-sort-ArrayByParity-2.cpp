#include <bits/stdc++.h>
using namespace std;
/*

*/

// Solution 1: Not a optimal solution
class Solution
{
public:
    vector<int> sortArrayByParityII(vector<int> &nums)
    {
        vector<int> even, odd, ans;
        int n = nums.size();
        for (int x : nums)
        {
            if (x % 2 == 0)
            {
                even.push_back(x);
            }
            else
                odd.push_back(x);
        }
        n /= 2; // Half elements are even else are odd
        int i = 0, j = 0, k = 0;
        while (i < n && j < n)
        {
            if (k % 2 == 0)
            {
                ans.push_back(even[i]);
                i++;
            }
            else
            {
                ans.push_back(odd[j]);
                j++;
            }
            k++;
        }
        ans.push_back(odd[n - 1]);
        return ans;
    }
};

// Solution 2: Optimal Solution
