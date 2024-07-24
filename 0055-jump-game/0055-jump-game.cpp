#include <algorithm>
class Solution {
public:
    void path(vector<int>& nums, vector<int>& memo, int i) {
        // if(i>=nums.size()-1){
        //    return true;
        // }
        int x = i + nums[i];
        if (x > nums.size() - 1) {
            x = nums.size() - 1;
        }
        for (int j = i; j <= x; j++) {

            if (memo[j] == -1) {
                memo[j] = 1;
                path(nums, memo, j);
            }
        }
    }
    bool canJump(vector<int>& nums) {
        int k = nums.size();
        vector<int> memo(k, -1);
        path(nums, memo, 0);

        if (memo[nums.size() - 1] == 1) {
            return true;
        }
        return false;
    }
};