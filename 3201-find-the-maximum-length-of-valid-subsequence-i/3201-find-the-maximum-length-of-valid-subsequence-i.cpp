class Solution {
public:
    int maximumLength(vector<int>& nums) {

        int ec = 0;
        int oc = 0;

        for (int n : nums) {
            if (n % 2 == 0)
                ec++;
            else
                oc++;
        }

        int f = 0;
        int c1 = 0;
        for (int i : nums) {
            if (i % 2 == 0 && f == 0) {
                c1++;
                f = 1;
            } else if (i % 2 != 0 && f != 0) {
                f = 0;
                c1++;
            }
        }
        f = 1;
        int c2 = 0;
        for (int i : nums) {
            if (i % 2 == 0 && f == 0) {
                c2++;
                f = 1;
            } else if (i % 2 != 0 && f != 0) {
                f = 0;
                c2++;
            }
        }
        return max(c1, max(c2, max(ec, oc)));
    }
};