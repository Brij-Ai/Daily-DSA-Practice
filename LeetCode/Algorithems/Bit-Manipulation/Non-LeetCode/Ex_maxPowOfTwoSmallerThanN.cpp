// Description: Given an integer n,find the maximum power of two that is smaller then n;
#include <iostream>
using namespace std;
// Approach 1.
int max_powerOfTwo(int x)
{
    int maxPower = 0;
    while (x != 0)
    {
        maxPower = x;
        x = x & (x - 1);
    }
    return maxPower;
}
// Approach 2.
int max_powerOfTwo_02(int n)
{
    n = n | (n >> 1);
    n = n | (n >> 2);
    n = n | (n >> 4);
    n = n | (n >> 8);
    n = n | (n >> 16);
    return (n + 1) >> 1;
}
int main()
{
    int x = 231;
    int ans = max_powerOfTwo(x);
    int ans_02 = max_powerOfTwo_02(x);
    cout << ans_02 << endl;
    cout << ans;
}