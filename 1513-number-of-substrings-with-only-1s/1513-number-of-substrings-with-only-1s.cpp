class Solution {
public:
    int numSub(string s) {
          const int MOD = 1000000007;
        int count = 0;
        int currentSequence = 0;

        for (char c : s) {
            if (c == '1') {
                currentSequence++;
                count = (count + currentSequence) % MOD;
            } else {
                currentSequence = 0; 
            }
        }

        return count;
    }
};