#include <iostream>
#include <vector>
using namespace std;
// Fails in most of the cases
class Solution
{
public:
    void segregateElements(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> pos, neg;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > 0)
            {
                pos.push_back(arr[i]);
            }
            else
            {
                neg.push_back(arr[i]);
            }
        }
        int i = 0;
        while (i < pos.size())
        {
            arr[i] = pos[i];
            i++;
        }
        // i++;
        int j = 0;
        while (j < neg.size())
        {
            arr[i] = neg[j];
            i++, j++;
        }
    }
};
int main()
{
    Solution s;
    vector<int> arr = {-1, 2, 4, -3, 2, -6};
    s.segregateElements(arr);
    for (int x : arr)
    {
        cout << x << " ";
    }
    return 0;
}