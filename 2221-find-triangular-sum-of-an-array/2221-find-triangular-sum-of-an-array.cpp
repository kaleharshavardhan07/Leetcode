class Solution {
public:
    int triangularSum(vector<int>& nums) {
        // vector<int> nums = nums;
        int k = nums.size();
        if (k == 1)
            return nums[0];
        while (k > 1) {
            // vector<int>r(nums.size()-1);
            for (int i = 0; i < k - 1; ++i) {

                nums[i] = (nums[i] + nums[i + 1]) % 10;
            }
            k--;
            //    nums=r;
        }
        if (nums.size() == 0) {
            return -1;
        }
        return nums[0];
    }
};