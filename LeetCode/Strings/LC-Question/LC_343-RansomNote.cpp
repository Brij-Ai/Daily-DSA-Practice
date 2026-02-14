/*
Description: https://leetcode.com/problems/ransom-note/
Author: Miao Zhang
*/

#include <string>
#include <vector>
using namespace std;

// Solution 1: using counter array

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        vector<int> count(26, 0);
        int n = ransomNote.size();
        for (int i = 0; i < n; i++)
        {
            count[ransomNote[i] - 'a']++;
        }
        for (int i = 0; i < magazine.size(); i++)
        {
            count[magazine[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++)
        {
            if (count[i] > 0)
                return false;
        }
        return true;
    }
};