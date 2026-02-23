#include <vector>
#include <string>
using namespace std;

// Solution 1: Time complexity O(n) and space complexity O(n);

class Solution
{
public:
    string restoreString(string s, vector<int> &indices)
    {
        int n = s.size();
        char ans[n];
        for (int i = 0; i < n; i++)
        {
            ans[indices[i]] = s[i];
        }
        for (int i = 0; i < n; i++)
        {
            s[i] = ans[i];
        }
        return s;
    }
};