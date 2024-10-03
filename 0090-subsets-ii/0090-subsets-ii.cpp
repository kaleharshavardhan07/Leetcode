class Solution {
public:
    void solve(vector<int>& nums, int cur, vector<int>& ret,
               vector<vector<int>>& reti) {
        
        reti.push_back(ret);
        for (int i = cur; i < nums.size(); i++) {
            if (i > cur && nums[i] == nums[i - 1])
                continue;
            ret.push_back(nums[i]);

            solve(nums, i+1, ret, reti);
            ret.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> ret;
        vector<vector<int>> reti;
        sort(nums.begin(), nums.end());
        solve(nums, 0, ret, reti);
        return reti;
    }
};