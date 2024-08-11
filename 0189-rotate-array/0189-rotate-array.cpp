class Solution {
public:
    void rotate(std::vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;  
        
        std::vector<int> ret(n);

        for (int i = 0; i < n; ++i) {
            ret[(i + k) % n] = nums[i];
        }

        nums = ret;
    }
};