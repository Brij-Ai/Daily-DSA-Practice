#include <iostream>
#include <vector>
using namespace std;
vector<int> dp;
int fibo(int n)
{
    if (n == 0 or n == 1)
        return n;
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = fibo(n - 1) + fibo(n - 2);
}
int main()
{
    int n;
    cout << "Enter : ";
    cin >> n;
    dp.clear();
    dp.resize(n + 1, -1);
    // 1 1 2 3 5 8 13 21
    cout << fibo(n);
    return 0;
}