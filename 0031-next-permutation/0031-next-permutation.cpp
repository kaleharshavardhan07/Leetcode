class Solution {
public:
    void nextPermutation(std::vector<int>& nums) {
        int n = nums.size();
        {

            int k = n - 2;
            while (k >= 0 && nums[k] >= nums[k + 1]) {
                k--;
            }

            if (k >= 0) {
                int l = n - 1;
                while (nums[k] >= nums[l]) {
                    l--;
                }

                std::swap(nums[k], nums[l]);
            }

            std::reverse(nums.begin() + k + 1, nums.end());
        }
    }
};