/*
Description:Given a fixed-length integer array arr, duplicate each occurrence of zero,
            shifting the remaining elements to the right.
            Note that elements beyond the length of the original array are not written.
            Do the above modifications to the input array in place and do not return anything.
Example 1:
            Input: arr = [1,0,2,3,0,4,5,0]
            Output: [1,0,0,2,3,0,0,4]
            Explanation: After calling your function, the input array is modified to: [1,0,0,2,3,0,0,4]
*/

/*
Approach 1: With new extra space where stored the our Answer
            Then copy its all elements in the original array

*/

// Solutions
#include <iostream>
#include <vector>
using namespace std;

// Code
class Solution
{
public:
    void duplicateZeros(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> cop(n);
        int j = 0;
        int i = 0;
        while (i < n and j < n)
        {
            if (arr[i] == 0)
            {
                cop[j++] = arr[i];
            } // write first zero
            if (j < n)
            { // check space BEFORE second write
                cop[j++] = arr[i];
            }
            i++; // move i once
        }
        for (int i = 0; i < n; i++)
        {
            arr[i] = cop[i];
        }
    }
};

int main()
{
    return 0;
}
