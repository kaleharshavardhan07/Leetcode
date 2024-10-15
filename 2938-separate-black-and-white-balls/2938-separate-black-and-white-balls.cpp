class Solution {
public:
    long long minimumSteps(string s) {
      
        long long zero = 0;
        long long swap = 0;
        for (char c : s) {
            if (c == '1')
                zero++;
            else
                swap += zero;
        }
        return swap;
    }
};