#include<iostream>
#include<vector>
using namespace std;

class solution{
    public:

    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    
    void dfs(int i, int j, vector<vector<int>> &grid, int org_color, int color){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != org_color) return;
        grid[i][j] = color; // Mark the cell with the new color
        // Recursively call dfs for all four adjacent cells
        for(int k = 0; k < 4; k++){
            int x = i + dx[k];
            int y = j + dy[k];

            dfs(x, y, grid, org_color, color);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int org_color = image[sr][sc];
        if(org_color != color){
            dfs(sr, sc, image, org_color, color);
        }
        return image;
    }
};