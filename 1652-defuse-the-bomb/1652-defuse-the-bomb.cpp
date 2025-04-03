class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ret(n, 0);

        if (k == 0) return ret;

        for (int i = 0; i < n; i++) {
            int sum = 0;

            if (k > 0) {
                // Sum of the next k elements
                for (int j = 1; j <= k; j++) {
                    sum += code[(i + j) % n];
                }
            } else {
                // Sum of the previous |k| elements
                for (int j = 1; j <= abs(k); j++) {
                    sum += code[(i - j + n) % n];
                }
            }

            ret[i] = sum;
        }

        return ret;
    }
};
