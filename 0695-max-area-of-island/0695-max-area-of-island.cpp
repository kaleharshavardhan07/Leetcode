class Solution {
public:
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int i,
             int j) {
        stack<pair<int, int>> st;
        int row = grid.size();
        int col = grid[0].size();
        st.push(make_pair(i, j));
        vis[i][j] = 1;
        while (!st.empty()) {
            pair<int, int> top = st.top();
            st.pop();
            int x = top.first;
            int y = top.second;

            if (y - 1 >= 0 && grid[x][y - 1] == 1 && vis[x][y - 1] == 0) {
                vis[x][y - 1] = 1;
                st.push(make_pair(x, y - 1));
            }
            if (y + 1 < col && grid[x][y + 1] == 1 && vis[x][y + 1] == 0) {
                vis[x][y + 1] = 1;
                st.push(make_pair(x, y + 1));
            }
            if (x - 1 >= 0 && grid[x - 1][y] == 1 && vis[x - 1][y] == 0) {
                vis[x - 1][y] = 1;
                st.push(make_pair(x - 1, y));
            }
            if (x + 1 < row && grid[x + 1][y] == 1 && vis[x + 1][y] == 0) {
                vis[x + 1][y] = 1;
                st.push(make_pair(x + 1, y));
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int count = 0;
        vector<vector<int>> vis(row, vector<int>(col, 0));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1 && vis[i][j] != 1) {
                    count++;
                    dfs(grid, vis, i, j);
                }
            }
        }
        return count;
    }
};