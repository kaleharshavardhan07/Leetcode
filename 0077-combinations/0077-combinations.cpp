class Solution {
public:
    void solve(int n, int k, int curr, int len, vector<int>& ret,
               vector<vector<int>>& reti) {

          if (ret.size() == k) {
            reti.push_back(ret);
            return;
        }
        
        
        if (curr > n) {
            return;
        }
        ret.push_back(curr);
        solve(n, k, curr+1, len+1, ret, reti);
        ret.pop_back();
        solve(n, k, curr+1, len, ret, reti);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> ret;
        vector<vector<int>> reti;
        solve(n, k, 1, 0, ret, reti);
        return reti;
    }
};