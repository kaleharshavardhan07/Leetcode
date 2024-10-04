class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        
        // Iterate over possible values for d (we start with the largest value of d)
        for (int d = n - 1; d >= 3; --d) {
            // Map to track sums of triplets (a + b + c)
            unordered_map<int, int> sumMap;
            
            // Iterate over possible values for c
            for (int c = d - 1; c >= 2; --c) {
                // Iterate over possible values for b
                for (int b = c - 1; b >= 1; --b) {
                    // Iterate over possible values for a
                    for (int a = b - 1; a >= 0; --a) {
                        // If the sum of nums[a] + nums[b] + nums[c] equals nums[d], we found a quadruplet
                        if (nums[a] + nums[b] + nums[c] == nums[d]) {
                            count++;
                        }
                    }
                }
            }
        }
        
        return count;
    }
};
