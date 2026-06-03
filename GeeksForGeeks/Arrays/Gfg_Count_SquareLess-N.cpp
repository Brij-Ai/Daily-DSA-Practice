// Description:https://www.geeksforgeeks.org/problems/count-squares3649/1
#include <iostream>
using namespace std;
class Solution
{
public:
    int countSquares(int n)
    {
        if (n <= 3)
            return 1;
        int count = 0;
        int number = 1;
        while (number * number < n)
        {
            count++;
            number++;
        }
        return count;
    }
};