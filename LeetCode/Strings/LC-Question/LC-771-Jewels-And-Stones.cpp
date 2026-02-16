/*
Description: jewels and stones: https://leetcode.com/problems/jewels-and-stones/
constraints:
1 <= J.length, S.length <= 50
J and S consist of only English letters.
All the characters of J are unique.
example:
Input: J = "aA", S = "aAAbbbb"
Output: 3
Input: J = "z", S = "ZZ"
Output: 0
Author: Miao Zhang
*/

#include <string>
using namespace std;

class Solution
{
public:
    int numJewelsInStones(string jewels, string stones)
    {
        int count = 0;
        for (int i = 0; i < jewels.size(); i++)
        {
            int j = 0;
            while (j < stones.size())
            {
                if (jewels[i] == stones[j])
                    count++;
                j++;
            }
        }
        return count;
    }
};