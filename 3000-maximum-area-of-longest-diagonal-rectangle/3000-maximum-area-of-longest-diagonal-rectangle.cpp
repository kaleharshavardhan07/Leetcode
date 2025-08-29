class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {

        int dig = INT_MIN;
        int a = 0;
        for (auto it : dimensions) {
            int t = it[0] * it[0] + it[1] * it[1];
            if (t > dig) {
                dig = t;
                a = it[0] * it[1];

            }

            else if (t == dig)
                a = max(a, it[0]*it[1]);
        }
        return a;
    }
};