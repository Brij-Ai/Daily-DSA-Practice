/*
Discretion:The array-form of an integer num is an array representing its digits in left to right order.
            For example, for num = 1321, the array form is [1,3,2,1].
            Given num, the array-form of an integer, and an integer k, return the array-form of the integer num + k.
Example 1:
        Input: num = [1,2,0,0], k = 34
        Output: [1,2,3,4]
        Explanation: 1200 + 34 = 1234
*/

#include <vector>
#include <algorithm>
using namespace std;
// Solution 1:
class Solution
{
public:
    vector<int> addToArrayForm(vector<int> &num, int k)
    {
        for (int i = num.size() - 1; i >= 0 && k > 0; --i)
        {
            num[i] += k;
            k = num[i] / 10;
            num[i] %= 10;
        }
        while (k > 0)
        {
            num.insert(num.begin(), k % 10);
            k /= 10;
        }
        return num;
    }
};

// Time Complexity: O(max(N, logK)), where N is the size of the input array num and K is the input integer k.
// Space Complexity: O(max(N, logK)), where N is the size of the input array num and K is the input integer k.
class Solution
{
public:
    std::vector<int> addToArrayForm(std::vector<int> &num, int k)
    {
        std::vector<int> result;
        int carry = 0;
        int i = num.size() - 1;

        while (i >= 0 || k > 0 || carry > 0)
        {
            int sum = carry;

            if (i >= 0)
            {
                sum += num[i];
                i--;
            }

            if (k > 0)
            {
                sum += k % 10;
                k /= 10;
            }

            result.push_back(sum % 10);
            carry = sum / 10;
        }

        std::reverse(result.begin(), result.end());
        return result;
    }
};