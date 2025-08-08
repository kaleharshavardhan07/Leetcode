class Solution {
public:
   unordered_map<int, unordered_map<int, double>> memo;

    double dp(int a, int b) {
        if (a <= 0 && b <= 0) return 0.5;
        if (a <= 0) return 1.0;
        if (b <= 0) return 0.0;

        if (memo[a][b] > 0) return memo[a][b];

        memo[a][b] = 0.25 * (
            dp(a - 100, b) +
            dp(a - 75, b - 25) +
            dp(a - 50, b - 50) +
            dp(a - 25, b - 75)
        );

        return memo[a][b];
    }
    double soupServings(int n) {
        if( n>4800)return 1;

        return dp(n,n);

    }
};