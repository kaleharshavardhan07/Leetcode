class Solution {
public:
    int minimumLength(string s) {
        vector<int> ret(26, 0);
        for (char c : s) {
            ret[c - 'a']++;
        }
        int c = 0;
        for (int i = 0; i < 26; i++) {
            if (ret[i] != 0) {
                if (ret[i] % 2 == 0) {
                    c += 2;

                } else {
                    c += 1;
                }
            }
        }
        return c;
    }
};