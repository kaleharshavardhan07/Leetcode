class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.length() == 0) {
            return true;
        }
        if (s.length() > t.length())
            return false;

        int i = 0;
        int j = 0;
        while (i < s.length() && j < t.length()) {
            if (s[i] == t[j]) {
                i++;
                j++;
                if (i == s.length() ) {
                    return true;
                }
            } else {
                j++;
            }
        }
        return false;
    }
};