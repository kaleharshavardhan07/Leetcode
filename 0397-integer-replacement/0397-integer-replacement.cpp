#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long solve(long long n, unordered_map<long long, long long>& memo) {
        if (n == 1) {
            return 0;
        }
        if (memo.find(n) != memo.end()) {
            return memo[n];
        }
        if (n % 2 == 0) {
            memo[n] = 1 + solve(n / 2, memo);
        } else {
            memo[n] = 1 + min(solve(n + 1, memo), solve(n - 1, memo));
        }
        return memo[n];
    }

    int integerReplacement(int n) {
        unordered_map<long long, long long> memo;
        return static_cast<int>(solve(n, memo));
    }
};
