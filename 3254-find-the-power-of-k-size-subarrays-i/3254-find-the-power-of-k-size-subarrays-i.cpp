class Solution {
public:
    int solve(vector<int>& nums, int start, int end) {
        int maxi = nums[start];
        for (int i = start + 1; i < end; i++) {
            if (nums[i] == nums[i - 1]+1) {
                maxi = max(maxi, nums[i]);
            } else {
                return -1;
            }
        }
        return maxi;
    }

    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> ret;
        for (int i = 0; i <= nums.size() - k; i++) {
            ret.push_back(solve(nums, i, i + k));
        }
        return ret;
    }
};
