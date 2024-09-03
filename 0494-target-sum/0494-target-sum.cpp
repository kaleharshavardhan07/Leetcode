class Solution {
public:
    int solve(vector<int>& nums, int target,int curr ){
        if(curr>nums.size())return 0;
        if(curr==nums.size()){
            if(target==0){
                return 1;
            }
            else {
                return 0;
            }

        }
        int take = solve(nums, target-nums[curr],curr+1);
        int nottake= solve(nums, target+nums[curr],curr+1);
        return take+nottake;

    }
    int findTargetSumWays(vector<int>& nums, int target) {
       return  solve(nums, target, 0);
    }
};