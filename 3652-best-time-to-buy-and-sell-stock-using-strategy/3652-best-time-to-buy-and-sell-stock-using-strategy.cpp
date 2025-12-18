class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();

        vector<long long> profitPrefix(n), pricePrefix(n);
        long long totalProfit = 0;

        // Build prefix sums
        for (int i = 0; i < n; i++) {
            totalProfit += 1LL * prices[i] * strategy[i];
            profitPrefix[i] = totalProfit;
            pricePrefix[i] = prices[i] + (i > 0 ? pricePrefix[i - 1] : 0);
        }

        long long ans = totalProfit;
        int half = k / 2;

        // Try modifying every window
        for (int i = 0; i + k <= n; i++) {

            // Old window contribution
            long long oldWindow =
                profitPrefix[i + k - 1] - (i > 0 ? profitPrefix[i - 1] : 0);

            // New window contribution
            int l = i + half;
            int r = i + k - 1;
            long long newWindow =
                pricePrefix[r] - (l > 0 ? pricePrefix[l - 1] : 0);

            long long curr =
                totalProfit - oldWindow + newWindow;

            ans = max(ans, curr);
        }

        return ans;
    }
};
