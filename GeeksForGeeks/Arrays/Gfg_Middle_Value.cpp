// Link: https://www.geeksforgeeks.org/problems/middle-of-three2926/1
// Description: Given three numbers, find the middle value among them.
// The middle value is the one that is neither the maximum nor the minimum of the three numbers.

#include <iostream>
using namespace std;
// Test case 1: a = 5, b = 10, c = 7 -> Output: 7
// Test case 2: a = 3, b = 1, c = 2 -> Output: 2
// Test case 3: a = 8, b = 6, c = 9 -> Output: 8
int middle(int a, int b, int c)
{
    if (a > b)
    {
        if (b > c)
            return b;
        else if (a > c)
            return c;
        else
            return a;
    }
    else
    {
        if (a > c)
            return a;
        else if (b > c)
            return c;
        else
            return b;
    }
}