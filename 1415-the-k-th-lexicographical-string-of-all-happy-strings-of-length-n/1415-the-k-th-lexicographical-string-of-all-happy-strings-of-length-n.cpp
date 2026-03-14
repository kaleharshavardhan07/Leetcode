class Solution {
public:
    void solve(int curr, int& n, char prev, string reti, vector<string>& ret) {
        if (curr == n) {
            ret.push_back(reti);
            return;
        }
        if (prev == 'a') {

            solve(curr + 1, n, 'b', reti + 'b', ret);
            solve(curr + 1, n, 'c', reti + 'c', ret);
        }
        if (prev == 'b') {

            solve(curr + 1, n, 'a', reti + 'a', ret);
            solve(curr + 1, n, 'c', reti + 'c', ret);
        }
        if (prev == 'c') {

            solve(curr + 1, n, 'b', reti + 'b', ret);
            solve(curr + 1, n, 'a', reti + 'a', ret);
        }
    }
    string getHappyString(int n, int k) {
        int curr = 0;
        vector<string> ret;
        solve(curr + 1, n, 'b', "b", ret);
        solve(curr + 1, n, 'a', "a", ret);
        solve(curr + 1, n, 'c', "c", ret);
        sort(ret.begin(), ret.end());
        if (k > ret.size())
            return "";
        return ret[k - 1];
    }
};