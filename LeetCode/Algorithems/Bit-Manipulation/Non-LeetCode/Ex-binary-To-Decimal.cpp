#include <iostream>
using namespace std;
int binaryToDecimal(string &str)
{
    int n = str.size();
    int res = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        char ch = str[i];
        int num = ch - '0';
        res = res + num * (1 << (n - i - 1));
    }
    return res;
}
int main()
{
    string str = "0001101";
    cout << binaryToDecimal(str);
}