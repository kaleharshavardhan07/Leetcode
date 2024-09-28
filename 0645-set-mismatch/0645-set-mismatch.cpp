class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int duplicate = -1, missing = -1;
        int n = nums.size();
        
        long long actual_sum = 0, expected_sum = (n * (n + 1)) / 2;
        
        for (int i = 0; i < n; i++) {
            actual_sum += nums[i];
            
            if (i > 0 && nums[i] == nums[i - 1]) {
                duplicate = nums[i];
            }
        }
        
        
        missing = (int)(expected_sum - (actual_sum - duplicate));
        
        return {duplicate, missing};
    }
};
