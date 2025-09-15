class Solution {
public:
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();

        // vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        // dp[0][0] = 1;

        // for (int i = 1; i < n; i++) {
        //     if (nums1[i] >= nums1[i - 1])
        //         dp[0][i] = 1 + dp[0][i - 1];
        // }
        // for (int i = 1; i < m; i++) {
        //     if (nums2[i] >= nums2[i - 1])
        //         dp[i][0] = 1 + dp[i - 1][0];
        // }
        // int maxi = 1;
        // for (int i = 1; i < m; i++) {
        //     for (int j = 1; j < n; j++) {
        //         int mini = min(nums1[j - 1], nums2[i - 1]);

        //         if (nums1[j] >= mini || nums2[i] >= mini) {
        //             dp[i][j] = 1+ max(dp[i][j], max(dp[i - 1][j], dp[i][j -
        //             1])); maxi = max(maxi, dp[i][j]);
        //         }
        //     }
        // }

        vector<int> dp1(n, 1);
        vector<int> dp2(n, 1);
        dp1[0] = 1;
        dp2[0] = 1;
        int maxi = 1;
        for (int i = 1; i < n; i++) {

            if (nums1[i] >= nums1[i - 1]) {
                dp1[i] = max(dp1[i], dp1[i - 1] + 1);
            }
            if (nums1[i] >= nums2[i - 1]) {
                dp1[i] = max(dp1[i], dp2[i - 1] + 1);
            }
            if (nums2[i] >= nums2[i - 1]) {
                dp2[i] = max(dp2[i], dp2[i - 1] + 1);
            }
            if (nums2[i] >= nums1[i - 1]) {
                dp2[i] = max(dp2[i], dp1[i - 1] + 1);
            }

            maxi = max(maxi, max(dp1[i], dp2[i]));
        }

        return maxi;
    }
};