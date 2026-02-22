class Solution {
public:
    int binaryGap(int n) {
        int prev = -1, pos = 0, maxi = 0;

        while (n > 0) {
            if (n & 1) {
                if (prev != -1) {
                    maxi = max(maxi, pos - prev);
                }
                prev = pos;
            }
            n >>= 1;
            pos++;
        }
        return maxi;
    }
};