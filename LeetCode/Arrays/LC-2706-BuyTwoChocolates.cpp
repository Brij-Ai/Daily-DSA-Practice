#include <vector>
using namespace std;

class Solution
{
public:
    int buyChoco(vector<int> &prices, int money)
    {
        int firstMin = 100, secMin = 100;
        for (int i = 0; i < prices.size(); i++)
        {
            if (prices[i] < firstMin)
            {
                secMin = firstMin;
                firstMin = prices[i];
            }
            else if (prices[i] < secMin)
            {
                secMin = prices[i];
            }
        }
        if (firstMin + secMin <= money)
            return money - (firstMin + secMin);
        else
            return money;
    }
};