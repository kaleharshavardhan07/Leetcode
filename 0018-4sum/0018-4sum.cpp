class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int s = nums.size();
         vector<vector<int>>ret;
        for (int i = 0; i < s - 3; i++) {
             if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < s - 2; j++) {
                 if (j> i+1 && nums[j] == nums[j - 1]) continue;
                int l = j + 1;
                int r = s - 1;
                while (l < r) {
                    if (nums[l] + nums[r] + nums[i] + nums[j] == target) {
                        ret.push_back({nums[l],nums[r],nums[i],nums[j]});
                         while (l < r && nums[l] == nums[l + 1]) l++;
                        while (l < r && nums[r] == nums[r - 1]) r--;
                        l++;
                        r--;
                    } else if (nums[l] + nums[r] + nums[i] + nums[j] < target) {
                        l++;

                    } else {
                        r--;
                    }
                }
            }
        }

        return ret;
    }
};