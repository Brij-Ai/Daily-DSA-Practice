#include <iostream>
#include <climits>
using namespace std;
// int main()
// {
//     int arr[] = {7, 4, 3, 1, 4, 7, 8, 9, 2, 1, 4};
//     int n = 11; // size of array
//     int k = 3;  // sub Array size
//     int sum = 0, maxSum = INT_MIN;
//     int maxIdx = -1;
//     for (int i = 0; i <= n - k; i++)
//     {
//         for (int j = i; j < i + k; j++)
//         {
//             sum += arr[j];
//         }
//         if (maxSum < sum)
//         {
//             maxSum = sum;
//             maxIdx = i;
//         }
//     }
//     cout << maxSum;
// }

// Sliding Window algorithem
int main()
{
    int arr[] = {7, 4, 3, 1, 4, 7, 8, 9, 2, 1, 4};
    int n = 11; // size of array
    int k = 4;  // sub Array size
    int maxSum = -1;
    int maxIdx = 0;
    int prevSum = 0;
    for (int i = 0; i < k; i++)
    {
        prevSum += arr[i];
    }
    maxSum = prevSum;
    int i = 1, j = k;
    // Sliding window
    while (j < n)
    {
        int currSum = prevSum + arr[j] - arr[i - 1];
        if (maxSum < currSum)
        {
            maxSum = currSum;
            maxIdx = i;
        }
        prevSum = currSum;
        i++, j++;
    }
    cout << maxSum;
}