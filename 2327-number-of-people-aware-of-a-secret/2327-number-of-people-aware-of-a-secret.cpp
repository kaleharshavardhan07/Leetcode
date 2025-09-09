class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long long> dp(n + 1, 0);

        dp[1] = 1;

        long long c = 0;
        long long b = 1e9 + 7;

        for (int i = 2; i <= n; i++) {
            if (i - delay > 0)
                c = (c+dp[i-delay]+b)%b;
            if (i - forget > 0)
                c=(c-dp[i-forget]+b)%b;
            dp[i] = c;
        }
        long long tot=0;
        for (int i=n-forget+1;i<=n;i++)
            tot=(tot+dp[i])%b;
        return (int)tot;
    }
};