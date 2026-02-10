/*
description: https://leetcode.com/problems/reverse-string/
solution: https://leetcode.com/problems/reverse-string/solutions/3455835/c-3-solutions-using-two-pointers-stl-reverse-and-recursion/
video: https://www.youtube.com/watch?v=HqPJF2L5h9Y
Given a string s, reverse the string and return it.
Example 1:
Input: s = "hello"
Output: "olleh"
Example 2
Input: s = "A man, a plan, a canal: Panama"
Output: "amanaP :lanac a ,nalp a ,nam A"

*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Solution 1: Using Two Pointers
//  Time Complexity: O(n), where n is the length of the input string s
//  Space Complexity: O(1), as we are reversing the string in place
class Solution
{
public:
    string reverseString(string s)
    {
        int left = 0;               // Pointer to the start of the string
        int right = s.length() - 1; // Pointer to the end of the string

        while (left < right)
        {
            swap(s[left], s[right]); // Swap characters at left and right pointers
            left++;                  // Move left pointer towards the center
            right--;                 // Move right pointer towards the center
        }

        return s; // Return the reversed string
    }
};

// Solution 2: Using STL reverse function
// Time Complexity: O(n), where n is the length of the input string s
// Space Complexity: O(1), as we are reversing the string in place
class Solution2
{
public:
    string reverseString(string s)
    {
        reverse(s.begin(), s.end()); // Use STL reverse function to reverse the string
        return s;                    // Return the reversed string
    }
};