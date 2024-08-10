class Solution {
public:
    bool solve(int n) {
        if (n == 1) {
            return false; 
        }

        bool f = false;
        for (int i = 1; i < n; ++i) {
            if (n % i == 0) { 
                
                if (!solve(n - i)) {
                    f = true;
                    break;
                }
            }
        }
        return f;
    }
    bool divisorGame(int n) { return solve(n); }
};