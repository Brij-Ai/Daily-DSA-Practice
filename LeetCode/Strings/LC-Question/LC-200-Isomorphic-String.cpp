/*
Description:
Given two strings s and t, determine if they are isomorphic.
Two strings s and t are isomorphic if the characters in s can be replaced to get t.
All occurrences of a character must be replaced with another character while preserving the order of characters.
No two characters may map to the same character.
For example, "egg" and "add" are isomorphic, while "foo" and "bar" are not.
Example 1:
Input: s = "egg", t = "add"
Output: true
Example 2:
Input: s = "foo", t = "bar"
Output: false
Example 3:
Input: s = "paper", t = "title"
Output: true
Constraints:
1 <= s.length <= 5 * 104
t.length == s.length
s and t consist of any valid ascii character.
Another test case: s = "badc", t = "kikp"
Output: false
important test case: s = "ab", t = "aa"
Output: false
*/

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;

// Approach: Using Hash Map and Hash Set
// Time Complexity: O(n), where n is the length of the input strings s and t
// Space Complexity: O(n), where n is the length of the input strings s and t
class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        if (s.length() != t.length())
        {
            return false;
        }

        unordered_map<char, char> charMap; // Map to store character mappings from s to t
        unordered_set<char> mappedChars;   // Set to track characters already mapped in t

        for (size_t i = 0; i < s.length(); ++i)
        {
            char charS = s[i];
            char charT = t[i];

            // If charS is already mapped, check if it maps to charT
            if (charMap.count(charS))
            {
                if (charMap[charS] != charT)
                {
                    return false; // Mismatch in mapping
                }
            }
            else
            {
                // If charS is not mapped, check if charT is already mapped to another character
                if (mappedChars.count(charT))
                {
                    return false; // charT is already mapped to another character
                }
                // Create the mapping and mark charT as mapped
                charMap[charS] = charT;
                mappedChars.insert(charT);
            }
        }

        return true; // All characters are properly mapped
    }
};

// Solution 2: Using Two Hash Maps
// Time Complexity: O(n), where n is the length of the input strings s and t
// Space Complexity: O(n), where n is the length of the input strings s and t
class Solution2
{
public:
    bool isIsomorphic(string s, string t)
    {
        if (s.length() != t.length())
        {
            return false;
        }

        unordered_map<char, char> mapST; // Map to store character mappings from s to t
        unordered_map<char, char> mapTS; // Map to store character mappings from t to s

        for (size_t i = 0; i < s.length(); ++i)
        {
            char charS = s[i];
            char charT = t[i];

            // Check mapping from s to t
            if (mapST.count(charS))
            {
                if (mapST[charS] != charT)
                {
                    return false; // Mismatch in mapping from s to t
                }
            }
            else
            {
                mapST[charS] = charT; // Create mapping from s to t
            }

            // Check mapping from t to s
            if (mapTS.count(charT))
            {
                if (mapTS[charT] != charS)
                {
                    return false; // Mismatch in mapping from t to s
                }
            }
            else
            {
                mapTS[charT] = charS; // Create mapping from t to s
            }
        }

        return true; // All characters are properly mapped in both directions
    }
};