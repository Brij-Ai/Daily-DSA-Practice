/*
Description:
Given a string s, return the string after replacing every uppercase letter with the same lowercase letter.
Example 1:
Input: s = "Hello"
Output: "hello"
Example 2:
Input: s = "here"
Output: "here"
Example 3:
Input: s = "LOVELY"
Output: "lovely"
Constraints:
1 <= s.length <= 100
s consists of printable ASCII characters.
*/

#include <string>
#include <algorithm>
using namespace std;
// Solution 1: Using built-in function tolower
class Solution
{
public:
    string toLowerCase(string s)
    {
        for (char &c : s)
        {
            c = tolower(c);
        }
        return s;
    }
};

// Solution 2: Using ASCII values to convert uppercase letters to lowercase
class Solution
{
public:
    string toLowerCase(string s)
    {
        for (char &c : s)
        {
            if (c >= 'A' && c <= 'Z')
            {
                c = c - 'A' + 'a'; // Convert uppercase to lowercase
            }
        }
        return s;
    }
};

// Solution 3: Using bit manipulation to convert uppercase letters to lowercase
class Solution
{
public:
    string toLowerCase(string s)
    {
        for (char &c : s)
        {
            if (c >= 'A' && c <= 'Z')
            {
                c = c | 32; // Set the 6th bit to convert uppercase to lowercase
            }
        }
        return s;
    }
};

// Solution 4: Using a mapping of uppercase to lowercase letters
class Solution
{
public:
    string toLowerCase(string s)
    {
        string result = "";
        for (char c : s)
        {
            if (c >= 'A' && c <= 'Z')
            {
                result += (c - 'A' + 'a'); // Convert uppercase to lowercase
            }
            else
            {
                result += c; // Keep the character unchanged
            }
        }
        return result;
    }
};
// Solution 5: Using the transform function from the algorithm library
class Solution
{
public:
    string toLowerCase(string s)
    {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        return s;
    }
};