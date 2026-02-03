#include <iostream>
#include <vector>
using namespace std;
/*
Test cases:
    input Arr[] = [2,1,3,5,1,2,6,7,5,6];
    Output Arr[] = [3,5]
*/
void find_TwoUniqueEle_InArray(vector<int> &arr)
{
    int n = arr.size();
    int res = 0;
    for (int i = 0; i < n; i++)
        res ^= arr[i];
    int temp = res; // reserving result
    int k = 0;
    while (true)
    {
        if ((temp & 1) == 1)
        {
            break;
        }
        k++;
    }
    int retVal = 0;
    for (int i = 0; i < n; i++)
    {
        int num = arr[i];
        if ((num >> k) & 1 == 1)
            retVal ^= num;
    }
    cout << retVal << endl;
    res = res ^ retVal;
    cout << res;
}
int main()
{
    cout << "hello";
    vector<int> arr = {2, 1, 3, 5, 1, 2, 6, 7, 5, 6};
    find_TwoUniqueEle_InArray(arr);
}