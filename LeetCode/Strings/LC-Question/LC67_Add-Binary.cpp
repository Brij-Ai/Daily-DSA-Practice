/*
Description:
Given two binary strings a and b, return their sum as a binary string.
Example 1:
Input: a = "11", b = "1"
Output: "100"
Example 2:
Input: a = "1010", b = "1011"
Output: "10101"
Constraints:
1 <= a.length, b.length <= 10^4
a and b consist only of '0' or '1' characters.
*/

#include <iostream>
#include <string>
#include <bitset>
using namespace std;

// Solution: Using bit manipulation and string manipulation
// Time Complexity: O(max(n, m)) where n and m are the lengths of the
// input strings a and b
// Space Complexity: O(max(n, m)) for the result string

class Solution
{
public:
    string addBinary(string a, string b)
    {
        string result = "";
        int carry = 0;
        int i = a.size() - 1;
        int j = b.size() - 1;

        while (i >= 0 || j >= 0 || carry)
        {
            int sum = carry;
            if (i >= 0)
                sum += a[i--] - '0';
            if (j >= 0)
                sum += b[j--] - '0';

            result = to_string(sum % 2) + result; // Append the current bit to the result
            carry = sum / 2;                      // Update the carry for the next iteration
        }

        return result;
    }
};

// Solution 2: Using built-in functions to convert binary strings to integers and back
// Time Complexity: O(max(n, m)) where n and m are the lengths of the
// input strings a and b
// Space Complexity: O(max(n, m)) for the result string
// Note: This solution may not work for very large binary strings due to integer overflow
class Solution
{
public:
    string addBinary(string a, string b)
    {
        long long num1 = stoll(a, nullptr, 2);                                   // Convert binary string a to integer
        long long num2 = stoll(b, nullptr, 2);                                   // Convert binary string b to integer
        long long sum = num1 + num2;                                             // Calculate the sum of the two integers
        return bitset<64>(sum).to_string().substr(64 - max(a.size(), b.size())); // Convert the sum back to binary string and remove leading zeros
    }
};