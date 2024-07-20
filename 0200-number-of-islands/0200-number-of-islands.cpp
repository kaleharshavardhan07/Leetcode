class Solution {
public:
    void bfs(vector<vector<char>>& grid, vector<vector<int>>&vis, int row,
             int col) {
        queue<pair<int, int>> q;
        int rowsize = grid.size();
        int colsize = grid[0].size();
        q.push({row, col});
        vis[row][col] = 1;
        vector<int> drow = {-1, 1, 0, 0};
        vector<int> dcol = {0, 0, -1, 1};
        while (!q.empty()) {
            int rowi = q.front().first;
            int coli = q.front().second;
            q.pop();

            for (int k = 0; k < 4; ++k) {
                int nrow = rowi + drow[k];
                int ncol = coli + dcol[k];

                if (ncol >= 0 && ncol < colsize && nrow >= 0 &&
                    nrow < rowsize && grid[nrow][ncol] == '1' &&
                    vis[nrow][ncol] == 0) {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        // int V = rows * cols;
        int count = 0;
        vector<vector<int>> vis(row, vector<int>(col, 0));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (vis[i][j] != 1 && grid[i][j] == '1') {
                    bfs(grid, vis, i, j);
                    count++;
                }
            }
        }
        return count;
    }
};