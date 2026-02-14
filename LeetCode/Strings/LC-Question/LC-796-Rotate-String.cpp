// Description: https://leetcode.com/problems/rotate-string/

#include <string>
using namespace std;

// Solution 1: Two Pointers
class Solution
{
public:
    bool rotateString(string A, string B)
    {
        if (A.size() != B.size())
            return false;
        if (A.empty())
            return true;
        int i = 0, j = 0;
        while (j < A.size())
        {
            if (A[i] == B[j])
            {
                i++;
                j++;
            }
            else
            {
                i = 0;
                if (A[i] != B[j])
                    j++;
            }
        }
        return i == A.size();
    }
};

class Solution
{
public:
    bool rotateString(string s, string goal)
    {
        if (s.size() != goal.size())
            return false;

        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            if (s == goal)
                return true;
            s = s.substr(1) + s[0]; // proper rotation
        }
        return false;
    }
};
