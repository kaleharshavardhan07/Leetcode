class Solution {
public:
    int bin(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r) {
            int md = (l + r) / 2;
            if (nums[md] == target) {
                return md;
            } else if (nums[md] > target) {
                r = md - 1;
            } else {
                l = md + 1;
            }
        }
        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {

        int k = bin(nums, target);
        if (k == -1) {
            return {-1, -1};
        }
        int min = k;
        while (min > 0 && nums[min - 1] == target) {
            min--;
        }

        int max = k;
        while (max < nums.size() - 1 && nums[max + 1] == target) {
            max++;
        }
        return {min,max};
    }
};