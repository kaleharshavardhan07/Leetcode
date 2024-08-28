class Solution {
public:
    const int MOD = 1e9 + 7;

    long long modPow(long long base, long long exp, int mod) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        long long even_positions = (n + 1) / 2;
        long long odd_positions = n / 2;

        long long good_even_count = modPow(5, even_positions, MOD);
        long long good_odd_count = modPow(4, odd_positions, MOD);

        return (good_even_count * good_odd_count) % MOD;
    }
};
