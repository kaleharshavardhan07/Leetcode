class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        int max = 0;
        int count = 1;
        vector<vector<int>> ret;
        int k = s.length();
        for (int i = 1; i < k; i++) {
            if (s[i] == s[i - 1]) {
                count++;

            } else {
                if (count >= 3) {

                    ret.push_back({i - count, i - 1});
                }
                count = 1;
            }
        }
         if (count >= 3) {
            ret.push_back({k - count, k - 1});
        }

        return ret;
    }
};