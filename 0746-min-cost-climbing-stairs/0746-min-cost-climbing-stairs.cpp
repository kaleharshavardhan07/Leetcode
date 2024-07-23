#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        
        // Handle edge cases
        if (n == 0) return 0;
        if (n == 1) return cost[0];
        
        // Initialize DP array
        vector<int> dp(n + 1, 0);
        
        // Base cases
        dp[0] = cost[0];
        dp[1] = cost[1];
        
        // Fill the DP array
        for (int i = 2; i <= n; ++i) {
            if (i < n) {
                dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
            } else {
                dp[i] = min(dp[i - 1], dp[i - 2]);
            }
        }
        
        // The answer is the minimum cost to reach the top
        return dp[n];
    }
};
