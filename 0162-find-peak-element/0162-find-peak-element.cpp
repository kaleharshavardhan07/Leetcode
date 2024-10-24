class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int ret;
        if(nums.size()==1){
            return 0;
        }
        
        if (nums[0] > nums[1]) {
            ret = 0;
        } else if (nums[nums.size() - 1] > nums[nums.size() - 2]) {
            ret = nums.size() - 1;
        } else {
            for (int i = 1; i < nums.size() - 1; i++) {
                if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {
                    ret = i;
                    break;
                }
            }
        }
        return ret;
    }
};