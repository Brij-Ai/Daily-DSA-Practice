#include <bits/stdc++.h>
using namespace std;

//  Solution
class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int countFive = 0;
        int countTen = 0;
        for (int x : bills)
        {
            if (x == 5)
                countFive++;
            if (x == 10)
            {
                if (countFive >= 1)
                {
                    countFive--;
                    countTen++;
                }
                else
                    return false;
            }
            if (x == 20)
            {
                if (countFive >= 1 && countTen >= 1)
                {
                    countTen--, countFive--;
                }
                else if (countFive >= 3)
                {
                    countFive -= 3;
                }
                else
                    return false;
            }
        }
        return true;
    }
};

class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int countFive = 0;
        int countTen = 0;
        for (int x : bills)
        {
            if (x == 5)
            {
                countFive++;
            }
            else if (x == 10)
            {
                if (countFive == 0)
                    return false;
                countFive--;
                countTen++;
            }
            else
            { // x == 20
                if (countTen > 0 && countFive > 0)
                {
                    countTen--;
                    countFive--;
                }
                else if (countFive >= 3)
                {
                    countFive -= 3;
                }
                else
                    return false;
            }
        }
        return true;
    }
};