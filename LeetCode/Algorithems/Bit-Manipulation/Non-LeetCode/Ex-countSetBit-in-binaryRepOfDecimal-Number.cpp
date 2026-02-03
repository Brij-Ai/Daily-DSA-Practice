#include <iostream>
using namespace std;

// Best approach
// Time complexity : 0(Total number of set bit)
int countSetBitInDeciNumber(int n)
{
    int count = 0;
    while (n > 0)
    {
        count++;
        n = (n & (n - 1)); // Removing the flipped bit from last set bit in number
    }
    return count;
}
int main()
{
    int decimalNumber = 4;
    // int countSetBit = __builtin_popcount(decimalNumber); // This built in method
    // cout << countSetBit;
    int countSetBit = countSetBitInDeciNumber(decimalNumber);
    cout << "Total set in : " << countSetBit;
}