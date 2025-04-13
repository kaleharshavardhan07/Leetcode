class Solution {
public:
    vector<int> solve(int a) {
        vector<int> ret(32, 0);
        for (int i = 31; i >= 0 && a > 0; --i) {
            ret[i] = a % 2;
            a = a / 2;
        }
        return ret;
    }
    int minFlips(int a, int b, int c) {

        vector<int> a1 = solve(a);
        vector<int> b1 = solve(b);

        vector<int> c1 = solve(c);
        int co = 0;

        for (int i = 0; i < 32; i++) {

            if (c1[i] == 0) {
                if (a1[i] == 1)
                    co++;
                if (b1[i] == 1)
                    co++;
            }
            if (c1[i] == 1) {
                if (a1[i] == 0 && b1[i] == 0)
                    co = co + 1;
            }
        }

        return co;
    }
};