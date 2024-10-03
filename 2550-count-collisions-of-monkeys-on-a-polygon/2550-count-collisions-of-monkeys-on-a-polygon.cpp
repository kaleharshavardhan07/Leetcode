class Solution {
public:
    int monkeyMove(int n) {
        const int MOD = 1000000007;
        long long result = power(2, n, MOD);
        return (result - 2 + MOD) % MOD;
    }
    
private:
    long long power(long long base, long long exp, int mod) {
        long long result = 1;
        base %= mod;
        while (exp > 0) {
            if (exp & 1) result = (result * base) % mod;
            base = (base * base) % mod;
            exp >>= 1;
        }
        return result;
    }
};