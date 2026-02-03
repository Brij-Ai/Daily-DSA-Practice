// Find the unique element the array that is not occurs twice in the arrays and except that one each element occurs twice
#include <iostream>
using namespace std;
int unique_ElementInIntegerArray(int nums[], int n)
{
    int unique = 0;
    for (int i = 0; i < n; i++)
    {
        unique ^= nums[i];
    }
    return unique;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 4, 1, 2, 3, 5, 6, 5}; // every Element occurs twice exept one element find that element(Unique)
    cout << "Unique element : " << unique_ElementInIntegerArray(arr, 11);
    return 0;
}