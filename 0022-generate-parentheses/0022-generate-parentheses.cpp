class Solution {
public:
    vector<string> app(int l, int r, int n, string s, vector<string>& ret) {

        if (l == n  && r == n ) {
            ret.push_back(s);
        } else if (l == n  && r < n) {
            app(l, r + 1, n, s + ")", ret);
        } else if (l < n && r < n) {

            if (l > r) {
                app(l, r + 1, n, s + ")", ret);
                app(l + 1, r, n, s + "(", ret);
            } else if (l == r) {
                app(l + 1, r, n, s + "(", ret);
            }
        }
        return ret;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        string s;
        app(0, 0, n, s, ret);
        return ret;
    }
};