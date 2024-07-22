class Solution {
public:
    int min(vector<int>& nums) {
        int m = INT_MAX;
        for (int c : nums) {
            if (m > c && c != 0)
                m = c;
        }
        return m;
    }
    int minimumOperations(vector<int>& nums) {
        int count = 0;
        int flag = 0;
        while (flag == 0) {
            int k = min(nums);
            if (k == INT_MAX) {
                flag = 1;
            } else {
                for (int i = 0; i < nums.size(); i++) {
                    if (nums[i] != 0) {
                        nums[i] -= k;
                        
                    }
                }
                count++;
            }
        }
        return count;
    }
};