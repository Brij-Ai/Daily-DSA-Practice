/*
Description: https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/
constraints:
1 <= n <= 1000
example:
Input: n = 5
Output: [-2,-1,0,1,2]
*/
#include <iostream>
#include <vector>
using namespace std;
/*
Solution 1: Time complxity O(n) and space complexity O(1);

*/

class Solution
{
public:
    vector<int> sumZero(int n)
    {
        if (n == 1)
            return {0};
        vector<int> ans(n);
        // ans[0] = n * (1-n) / 2;
        for (int i = 0; i < n; i++)
            ans[i] = i * 2 - n + 1;
        return ans;
    }
};

// solution 2:
class Solution
{
public:
    vector<int> sumZero(int n)
    {
        vector<int> ans(n);
        ans[0] = n * (1 - n) / 2;
        for (int i = 1; i < n; i++)
            ans[i] = i;
        return ans;
    }
};
