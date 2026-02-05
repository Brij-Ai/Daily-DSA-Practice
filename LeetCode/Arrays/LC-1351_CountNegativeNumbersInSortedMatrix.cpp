/*
Description: Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise,
            return the number of negative numbers in grid.
*/

#include <iostream>
#include <vector>
using namespace std;

// Solution:
class Solution
{
public:
    int countNegatives(vector<vector<int>> &grid)
    {
        int count = 0;
        int n = grid.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] < 0)
                    count++;
            }
        }
        return count;
    }
};