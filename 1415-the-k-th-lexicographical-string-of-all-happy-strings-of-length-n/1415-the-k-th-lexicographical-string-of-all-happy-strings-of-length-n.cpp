class Solution {
public:
    void solve(set<string>& mp, string s, char last, int i, int n) {

        if (i == n) {
            mp.insert(s);

            return;
        } else {
            if (last == 'a') {
                solve(mp, s + 'b','b', i+1, n);
                solve(mp, s + 'c','c', i+1, n);
            }
            if (last == 'b') {
                solve(mp, s + 'a','a', i+1, n);
                solve(mp, s + 'c','c', i+1, n);
            }
            if (last == 'c') {
                solve(mp, s + 'b','b', i+1, n);
                solve(mp, s + 'a','a', i+1, n);
            }
        }
    }
    string getHappyString(int n, int k) {

        set<string> mp;
        string s;
        vector<string> ret;
        solve(mp, "a",'a', 1, n);
        solve(mp, "b",'b', 1, n);
        solve(mp, "c",'c', 1, n);
        for (auto it : mp) {
            ret.push_back(it);
        }

        sort(ret.begin(), ret.end());
        if (k > ret.size())
            return "";
        return ret[k - 1];
    }
};