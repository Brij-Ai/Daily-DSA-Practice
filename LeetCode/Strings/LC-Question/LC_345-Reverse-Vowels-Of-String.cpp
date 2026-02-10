/*
Description:
            Given a string s, reverse only the vowels in the string and return it.
            Example 1:
            Input: s = "hello"
            Output: "holle"
            Example 2:
            Input: s = "leetcode"
            Output: "leotcede"
            Constraints:
            1 <= s.length <= 3 * 105
            s consists of printable ASCII characters.
*/
#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;
// Solution 1: Using Two Pointers
// Time Complexity: O(n), where n is the length of the input string s
// Space Complexity: O(1), as we are reversing the vowels in place
class Solution
{
public:
    string reverseVowels(string s)
    {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'}; // Set of vowels for quick lookup
        int left = 0;                                                                    // Pointer to the start of the string
        int right = s.length() - 1;                                                      // Pointer to the end of the string

        while (left < right)
        {
            // Move left pointer until it points to a vowel
            while (left < right && !vowels.count(s[left]))
            {
                left++;
            }

            // Move right pointer until it points to a vowel
            while (left < right && !vowels.count(s[right]))
            {
                right--;
            }

            if (left < right)
            {
                swap(s[left], s[right]); // Swap the vowels at left and right pointers
                left++;                  // Move left pointer towards the center
                right--;                 // Move right pointer towards the center
            }
        }

        return s; // Return the string with reversed vowels
    }
};
