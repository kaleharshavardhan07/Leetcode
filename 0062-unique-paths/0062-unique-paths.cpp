// class Solution {
// public:
//     int ret(int i, int j, int m, int n) {
//         int k, l;
//         if (i < m-1) {
//             k = ret(i + 1, j, m, n);
//         }
//         if (j < n-1) {
//             l = ret(i, j + 1, m, n);
//         }
//         if (i == m-1) {
//             return 1;
//         }
//         if (j == n-1) {
//             return 1;
//         }
//         return k + l;
//     }
//     int uniquePaths(int m, int n) {
//         int i = 0;
//         int j = 0;
//         int ans = ret(i, j, m, n);

//             return ans;
//     }
// };



class Solution {
public:
    int uniquePaths(int m, int n) {
        // Create a 2D DP table
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        // Initialize base case: Only 1 way to reach the starting point
        dp[0][0] = 1;
        
        // Fill the DP table
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // Add ways from the top (if exists) and left (if exists)
                if (i > 0) {
                    dp[i][j] += dp[i - 1][j];
                }
                if (j > 0) {
                    dp[i][j] += dp[i][j - 1];
                }
            }
        }
        
        // The answer is stored in dp[m-1][n-1]
        return dp[m - 1][n - 1];
    }
};
