#include <iostream>
using namespace std;
int min_NumberOfBitsToConvertNumberToAnotherNumber(int Number, int convertNumber)
{
    int res = 0;
    res = Number ^ convertNumber;
    // int countSetBitInRes = __builtin_popcount(res); //count how many set bit present in number
    int countSetBit = 0;
    while (res > 0)
    {
        countSetBit++;
        res = res & (res - 1);
    }
    return countSetBit;
}
int main()
{
    int Number = 5;
    int requiredNuber = 11;
    cout << "Total min no of bit to flips in number : " << min_NumberOfBitsToConvertNumberToAnotherNumber(5, 11);
    return 0;
}