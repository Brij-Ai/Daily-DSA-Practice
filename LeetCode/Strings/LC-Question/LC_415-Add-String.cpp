/*
Description: Given two non-negative integers num1 and num2 represented as strings, return the sum of num1 and num2 as a string.
Example 1:
Input: num1 = "11", num2 = "123"
Output: "134"
Example 2:
Input: num1 = "456", num2 = "77"
Output: "533"
Example 3:
Input: num1 = "0", num2 = "0"
Output: "0"
Constraints:
1 <= num1.length, num2.length <= 104
num1 and num2 consist of only digits.
num1 and num2 do not contain any leading zeros except for the zero itself.
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Solution class to add two strings representing non-negative integers
class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        string result;           // To store the final result
        int carry = 0;           // To keep track of carry during addition
        int i = num1.size() - 1; // Pointer for num1
        int j = num2.size() - 1; // Pointer for num2

        // Loop until both strings are processed or there is a carry left
        while (i >= 0 || j >= 0 || carry)
        {
            int sum = carry; // Start with the carry from the previous iteration

            // Add digit from num1 if available
            if (i >= 0)
            {
                sum += num1[i] - '0'; // Convert char to int
                i--;                  // Move pointer left
            }

            // Add digit from num2 if available
            if (j >= 0)
            {
                sum += num2[j] - '0'; // Convert char to int
                j--;                  // Move pointer left
            }

            carry = sum / 10;                   // Update carry for next iteration
            result.push_back((sum % 10) + '0'); // Append current digit to result
        }

        reverse(result.begin(), result.end()); // Reverse the result to get the correct order
        return result;                         // Return the final sum as a string
    }
};