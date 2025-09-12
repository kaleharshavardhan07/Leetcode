class Solution {
public:
    bool doesAliceWin(string s) {
        string vl = "aeiou";
        unordered_set<char> v(vl.begin(), vl.end());
        int tl_vl = 0;

        for (char c : s) {
            if (v.count(c))
                tl_vl++;
        }
        return tl_vl>0;
    }
};