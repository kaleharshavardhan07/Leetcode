class Solution {
public:

    int solve(const string& s, int i, unordered_map<int, int>& memo) {
        if (i == s.size()) return 1; 
        if (s[i] == '0') return 0;    
        if (memo.find(i) != memo.end()) return memo[i];

        int nottake = solve(s, i + 1, memo); 
        int take = 0;
        if (i < s.size() - 1) {
            int two_digit = stoi(s.substr(i, 2));
            if (two_digit >= 10 && two_digit <= 26) {
                take = solve(s, i + 2, memo);  
            }
        }
        
        memo[i] = take + nottake;  
        return memo[i];
    }
    int numDecodings(string s) {
        unordered_map<int, int> memo;
        return solve(s, 0, memo);
    }
};