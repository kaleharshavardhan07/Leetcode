class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int max = 0;

        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        dp[0][0] = matrix[0][0];
        // for (int i = 1; i < m; i++) {
        //     dp[i][0] = dp[i - 1][0] + matrix[i][0];
        // }
        for (int i = 1; i < n; i++) {
            dp[0][i] = matrix[0][i];
        }
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int up = matrix[i][j] + dp[i - 1][j];
                int left = matrix[i][j];
                if (j - 1 >= 0) {
                    left += dp[i - 1][j - 1];

                } else
                    left += 1e7;
                int right = matrix[i][j];
                if (j + 1 < n) {
                    right += dp[i - 1][j + 1];

                } else
                    right += 1e7;
                dp[i][j] = min(up, min(left, right));
            }
        }
        int mini = INT_MAX;
        for (int i = 0; i < m; i++) {

            mini = min(mini, dp[m - 1][i]);
        }
        return mini;
    }
};