/*
description: https://leetcode.com/problems/valid-anagram/
Given two strings s and t, return true if t is an anagram of s, and false otherwise.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
Example 1:
Input: s = "anagram", t = "nagaram"
Output: true
Example 2:
Input: s = "rat", t = "car"
Output: false

*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Solution 1: Using sorting
// Time Complexity: O(n log n) due to sorting
// Space Complexity: O(1) if we ignore the space used by sorting, otherwise O(n) due to the sorted strings

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if (s.size() != t.size())
            return false;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != t[i])
                return false;
        }
        return true;
    }
};

// Solution 2: Using frequency counting
// Time Complexity: O(n) where n is the length of the strings
// Space Complexity: O(1) since we are using a fixed size array for counting characters

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
            return false;

        int count[26] = {0}; // Assuming only lowercase letters

        for (int i = 0; i < s.size(); i++)
        {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }

        for (int i = 0; i < 26; i++)
        {
            if (count[i] != 0)
                return false;
        }
        return true;
    }
};

// You can test the above solutions using the main function below:

int main()
{
    Solution sol;
    string s = "anagram";
    string t = "nagaram";
    cout << sol.isAnagram(s, t) << endl; // Output: 1 (true)

    s = "rat";
    t = "car";
    cout << sol.isAnagram(s, t) << endl; // Output: 0 (false)

    return 0;
}
