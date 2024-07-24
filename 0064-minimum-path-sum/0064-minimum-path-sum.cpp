class Solution {

public:
 
    int mini(vector<vector<int>>& grid, int i, int j, int col, int row,vector<vector<int>>& memo) {
        int r, d;
         if (memo[i][j] != -1) return memo[i][j];
        if (i < row && j < col) {
            r = grid[i][j] + mini(grid, i, j + 1, col, row, memo);
            d = grid[i][j] + mini(grid, i + 1, j, col, row, memo);

        } else if (i < row && j == col) {
            d = grid[i][j] + mini(grid, i + 1, j, col, row, memo);
            r = INT_MAX;

        } else if (i == row && j < col) {
            r = grid[i][j] + mini(grid, i, j + 1, col, row, memo);
            d = INT_MAX;
        } else {
            return grid[i][j];
        }
        memo[i][j] = min(r, d);

        return memo[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int col = grid[0].size();
        int row = grid.size();
        int i = 0, j = 0;

        vector<vector<int>> memo(row, vector<int>(col, -1));
       
        int k = mini(grid, i, j, col - 1, row - 1, memo);
        return k;
    }
};