class Solution {
public:
    int solve(vector<vector<int>> &dp, string &text1, string &text2, int ind1, int ind2) {
        if (ind1 < 0 || ind2 < 0) {
            return 0;
        }
        if (dp[ind1][ind2] != -1)
            return dp[ind1][ind2];

        if (text1[ind1] == text2[ind2]) {
            dp[ind1][ind2] = 1 + solve(dp, text1, text2, ind1 - 1, ind2 - 1); 
        } else {
            dp[ind1][ind2] = max(solve(dp, text1, text2, ind1 - 1, ind2), 
                                 solve(dp, text1, text2, ind1, ind2 - 1));
        }

        return dp[ind1][ind2];
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(dp, text1, text2, n - 1, m - 1);
    }
};
