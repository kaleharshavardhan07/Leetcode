class Solution {
public:
    int mod = 1e9 + 7;

    long long power(int base, int exp) {
        long long result = 1;
        long long b = base;
        while (exp > 0) {
            if (exp & 1) {
                result = (result * b) % mod;
            }
            b = (b * b) % mod;
            exp >>= 1;
        }
        return result;
    }
    
    void solve(int n, int x, int curr, long long sum, int& count) {
        if (sum > n) return;
        
        if (sum == n) {
            count = (count + 1) % mod;
            return;
        }
        if( curr>n)return;
        long long currPow = power(curr, x);
        if (sum + currPow <= n) {
            solve(n, x, curr + 1, sum + currPow, count);
        }
        
        solve(n, x, curr + 1, sum, count);
    }
    
    int numberOfWays(int n, int x) {
       vector<int> dp(n + 1, 0);
        dp[0] = 1;
        
        int curr = 1;
        while (true) {
            long long currp = power(curr, x);
            if (currp > n) break; 
            
            for (int sum = n; sum >= currp; sum--) {
                dp[sum] = (dp[sum] + dp[sum - currp]) % mod;
            }
            curr++;
        }
        
        return dp[n];
    }
};