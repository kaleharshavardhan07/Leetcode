#include <unordered_map>

class Solution {
private:
    std::unordered_map<int, int> memo;
    
    int solve(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        
        if (memo.find(n) != memo.end()) {
            return memo[n];
        }
        
        memo[n] = solve(n - 1) + solve(n - 2);
        return memo[n];
    }
    
public:
    int climbStairs(int n) {
        return solve(n);
    }
};
