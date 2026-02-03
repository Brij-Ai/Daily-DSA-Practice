#include <iostream>
#include <climits>
using namespace std;
int main()
{
    int arr[] = {1, 2, 4, 1, 4, 3, 5, 3, 6, 6, 9, 6, 61, 62, 62, 9};
    int n = 16;
    int max_Ele = INT_MIN;
    int ans = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max_Ele)
        {
            max_Ele = arr[i];
            count = 1;
        }
        else if (arr[i] == max_Ele)
        {
            count++;
        }
        ans = max(count, ans);
    }
    cout << ans;
    return 0;
}