class Solution {
public:
    int countSetBits(int n) { return __builtin_popcount(n); }

    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] > nums[i]) {
                    if (countSetBits(nums[j]) == countSetBits(nums[i])) {
                        swap(nums[j], nums[i]);
                    } else {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};