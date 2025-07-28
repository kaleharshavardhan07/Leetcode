class Solution {
public:
    void solve(vector<int>& nums, int curr, int sum, map<int, int>& mp) {

        if (curr == nums.size()) {
            mp[sum]++;
            return;
        }

        solve(nums, curr + 1, sum | nums[curr], mp);
        solve(nums, curr + 1, sum, mp);
    }
    int countMaxOrSubsets(vector<int>& nums) {

        map<int, int> mp;
        int curr = 0;
        int sum = 0;
        solve(nums, curr, sum, mp);
        int maxi = 0;
        for (auto it : mp) {
            maxi = max(maxi, it.second);
        }

        return maxi;
    }
};