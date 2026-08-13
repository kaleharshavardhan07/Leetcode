class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                // Add the top element if it exists
                if (i > 0) grid[i][j] += grid[i - 1][j];
                
                // Add the left element if it exists
                if (j > 0) grid[i][j] += grid[i][j - 1];
                
                // Subtract the top-left diagonal element if both exist to avoid double counting
                if (i > 0 && j > 0) grid[i][j] -= grid[i - 1][j - 1];

                // Every submatrix must include grid[0][0], so grid[i][j] 
                // now represents the total sum of the submatrix from (0,0) to (i,j)
                if (grid[i][j] <= k) {
                    count++;
                }
            }
        }
        return count;
    }
};
