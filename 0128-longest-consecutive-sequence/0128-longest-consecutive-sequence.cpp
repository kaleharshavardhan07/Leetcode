class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if (nums.size() == 0)
            return 0;
        int maxi = 1;
        int curr = 1;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] + 1 == nums[i + 1]) {
                curr++;
                maxi = max(maxi, curr);
            } else if (nums[i] == nums[i + 1])
                continue;
            else {
                maxi = max(maxi, curr);
                curr = 1;
            }
        }
        return maxi;
    }
};