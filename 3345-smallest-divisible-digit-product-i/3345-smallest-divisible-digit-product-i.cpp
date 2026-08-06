class Solution {
public:
    int solve(int k) {

        if (k < 0)
            k = -k;

        std::string s = std::to_string(k);
        int tot = 1;

        for (char c : s) {
            tot *= (c - '0');
        }

        return tot;
    }
    int smallestNumber(int n, int t) {
        int m = 0;
        int k = n;
        while (m == 0) {
            int num = solve(k);
            if (num % t == 0) {
                m = 1;
            } else {
                k++;
            }
        }
        return k;
    }
};