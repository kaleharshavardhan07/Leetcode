class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        vector<vector<int>> ans(m, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;
        vector<int> dir = {-1, 0, 1, 0, -1};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    ans[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();

            for (int d = 0; d < 4; d++) {
                int ni = p.first + dir[d];
                int nj = p.second + dir[d + 1];

                if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
                    if (ans[ni][nj] > ans[p.first][p.second] + 1) {
                        ans[ni][nj] = ans[p.first][p.second] + 1;
                        q.push({ni, nj});
                    }
                }
            }
        }

        return ans;
    }
};
