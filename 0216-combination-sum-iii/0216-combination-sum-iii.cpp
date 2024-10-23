class Solution {
public:
    void solve(vector<vector<int>>& reti, vector<int> map, vector<int> ret,int prev,
               int k, int sum) {
        if (k == 0 && sum == 0) {
            reti.push_back(ret);
            return;
        }
        if (k <= 0 || sum < 0)
            return;

        for (int i = prev+1; i < 10; i++) {
            if (map[i] != 1 && sum - i >= 0) {
                k--;
                sum = sum - i;
                ret.push_back(i);
                map[i]=1;
                solve(reti, map, ret,i, k, sum);
                map[i]=0;
                ret.pop_back();
                k++;
                sum = sum + i;
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> reti;
        if (n < k) {
            return reti;
        }

        vector<int> map(10, 0);
        vector<int>ret;

        map[0] = 1;

        solve( reti, map, ret,0, k, n);

        return reti;
    }
};