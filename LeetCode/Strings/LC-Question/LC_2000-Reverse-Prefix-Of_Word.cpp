/*
Description:Given a 0-indexed string word and a character ch,
reverse the segment of word that starts at index 0 and ends at the index of the first occurrence of ch (inclusive).
If the character ch does not exist in word, do nothing.
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Solution class to reverse the prefix of a word up to a specified character
class Solution
{
public:
    string reversePrefix(string word, char ch)
    {
        int index = word.find(ch); // Find the index of the specified character

        // If the character is not found, return the original word
        if (index == -1)
            return word;

        // Reverse the prefix of the word up to the found index
        reverse(word.begin(), word.begin() + index + 1);
        return word; // Return the modified word
    }
};

// Solution 2: Using a loop to reverse the prefix without using the built-in reverse function
class Solution2
{
public:
    string reversePrefix(string word, char ch)
    {
        int index = word.find(ch); // Find the index of the specified character

        // If the character is not found, return the original word
        if (index == -1)
            return word;

        // Create a new string to store the reversed prefix and the remaining part of the word
        string result;
        for (int i = index; i >= 0; i--)
        {
            result.push_back(word[i]); // Append characters in reverse order
        }
        result += word.substr(index + 1); // Append the remaining part of the word
        return result;                    // Return the modified word
    }
};

// Solution 3: Using a two-pointer approach to reverse the prefix in place
class Solution3
{
public:
    string reversePrefix(string word, char ch)
    {
        int index = word.find(ch); // Find the index of the specified character

        // If the character is not found, return the original word
        if (index == -1)
            return word;

        // Use two pointers to reverse the prefix in place
        int left = 0;
        int right = index;
        while (left < right)
        {
            swap(word[left], word[right]); // Swap characters at left and right pointers
            left++;                        // Move left pointer to the right
            right--;                       // Move right pointer to the left
        }
        return word; // Return the modified word
    }
};

// Solution 4:

class Solution
{
public:
    string reversePrefix(string word, char ch)
    {
        int pos = 0;
        for (int i = 0; i < word.size(); i++)
        {
            if (word[i] == ch)
            {
                pos = i;
                break;
            }
        }
        int i = 0;
        while (i < pos)
            swap(word[i++], word[pos--]);
        return word;
    }
};
