class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        int target = 0;
        for (int num : nums) {
            target = (target + num) % p;
        }
        
        if (target == 0) return 0;
        
        unordered_map<int, int> last_seen{{0, -1}};
        int current_sum = 0;
        int min_length = n;
        
        for (int i = 0; i < n; i++) {
            current_sum = (current_sum + nums[i]) % p;
            int to_find = (current_sum - target + p) % p;
            
            if (last_seen.count(to_find)) {
                min_length = min(min_length, i - last_seen[to_find]);
            }
            
            last_seen[current_sum] = i;
        }
        
        return min_length < n ? min_length : -1;
    }
};