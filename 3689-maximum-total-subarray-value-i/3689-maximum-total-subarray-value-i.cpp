class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int maxVal = nums[0];
        int minVal = nums[0];

        for (int num : nums) {
            if (num > maxVal) maxVal = num;
            if (num < minVal) minVal = num;
        }

        return 1LL * (maxVal - minVal) * k;
    }
};
