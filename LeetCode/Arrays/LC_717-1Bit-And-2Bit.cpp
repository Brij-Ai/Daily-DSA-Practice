/*
Description:We have two special characters:
The first character can be represented by one bit 0.
The second character can be represented by two bits (10 or 11).
Given a binary array bits that ends with 0, return true if the last character must be a one-bit character

Input: bits = [1,0,0]
Output: true
Explanation: The only way to decode it is two-bit character and one-bit character.
So the last character is one-bit character.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isOneBitCharacter(vector<int> &bits)
    {
        int n = bits.size();
        int i = 0;
        while (i < n - 1)
        {
            if (bits[i] == 0)
            {
                i++;
            }
            else
                i += 2;
        }
        return i == n - 1;
    }
};

int main()
{
    Solution test;
    vector<int> arr = {1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0};
    cout << test.isOneBitCharacter(arr);
}
