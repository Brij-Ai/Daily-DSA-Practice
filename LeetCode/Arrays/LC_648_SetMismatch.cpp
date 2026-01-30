/*Description : You have a set of integers s, which originally contains all the numbers from 1 to n.
 Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.
 You are given an integer array nums representing the data status of this set after the error.
 Find the number that occurs twice and the number that is missing and return them in the form of an array.
 Note : Element can be in any sequence */

// Time complexity : O(n)
// Space complexity : O(n)
// input arr[] = [2,3,4,5,6,7,7]
// output [7,1]

// Solution With a extra space (Not a optimal approach) and used some maths like Sum of all element 1 to n = n*(n+1)/2
// This can be solve without extra space

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// Solution
class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        unordered_set<int> st; // Extra space
        int n = nums.size();   // size of List
        int duplicateNum = 0, missingEle = 0, sumOfArray = 0;

        for (int data : nums)
        {
            sumOfArray += data;
            // use contains instead of count {st.contans(data)}
            if (st.count(data)) // Finding repeating element
            {
                duplicateNum = data; // getting repeating element in array
            }
            st.insert(data);
        }
        int sumOfUpToN = n * (n + 1) / 2;
        sumOfArray -= duplicateNum;
        missingEle = sumOfUpToN - sumOfArray;
        return {duplicateNum, missingEle};
    }
};

// Solution 2.(imp technique)
// Time complexity : O(n)
// Space complexity : O(1)
// Approach : change the element through
class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        int n = nums.size();
        int missing = -1, dup = -1;
        for (int i = 0; i < n; i++)
        {
            if (nums[abs(nums[i]) - 1] < 0)
            {
                dup = abs(nums[i]);
            }
            else
            {
                nums[abs(nums[i]) - 1] *= (-1);
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0)
            {
                missing = (i + 1);
                break;
            }
        }
        return {dup, missing};
    }
};
