class Solution {
public:
    bool backspaceCompare(string s, string t) {
        vector<char> s1;
        vector<char> s2;
        for (char c : s) {
            if (c == '#') {
                if (!s1.empty())
                    s1.pop_back();
            } else {
                s1.push_back(c);
            }
        }
        for (char c : t) {
            if (c == '#') {
                if (!s2.empty())
                    s2.pop_back();
            } else {
                s2.push_back(c);
            }
        }
        if (s1.size() != s2.size())
            return false;
        else {
            for (int i = 0; i < s1.size(); i++) {
                if (s1[i] != s2[i]) {
                    return false;
                }
            }
        }
        return true;
    }
};