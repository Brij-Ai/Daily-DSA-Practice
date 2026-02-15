/*
Description: https://leetcode.com/problems/fizz-buzz/
Author: Miao Zhang
*/

#include <vector>
#include <string>
using namespace std;

// Solution 1: Simulation
class Solution
{
public:
    vector<string> fizzBuzz(int n)
    {
        vector<string> result;
        for (int i = 1; i <= n; i++)
        {
            if (i % 3 == 0 && i % 5 == 0)
                result.push_back("FizzBuzz");
            else if (i % 3 == 0)
                result.push_back("Fizz");
            else if (i % 5 == 0)
                result.push_back("Buzz");
            else
                result.push_back(to_string(i));
        }
        return result;
    }
};

// Solution 2: String Concatenation
class Solution
{
public:
    vector<string> fizzBuzz(int n)
    {
        vector<string> result;
        for (int i = 1; i <= n; i++)
        {
            string s = "";
            if (i % 3 == 0)
                s += "Fizz";
            if (i % 5 == 0)
                s += "Buzz";
            if (s.empty())
                s = to_string(i);
            result.push_back(s);
        }
        return result;
    }
};