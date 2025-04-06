class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
   if (nums.empty()) return {};

        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n, 1), prev(n, -1);
        int maxIndex = 0;

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if (dp[i] > dp[maxIndex]) {
                maxIndex = i;
            }
        }

        vector<int> ret;
        for (int i = maxIndex; i >= 0; i = prev[i]) {
            ret.push_back(nums[i]);
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};