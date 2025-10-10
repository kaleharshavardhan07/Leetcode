#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        vector<int> dp(n, INT_MIN);

        int maxi = INT_MIN;
        int q = INT_MIN;

        for (int i = 0; i < n; i++) {
            if (i - k >= 0)
                dp[i] = max(energy[i] + dp[i - k], energy[i]);
            else
                dp[i] = energy[i];
        }
        for (int i = n - 1; i >= n - k; i--) {
            maxi = max(maxi, dp[i]);
        }

        return maxi;
    }
};
