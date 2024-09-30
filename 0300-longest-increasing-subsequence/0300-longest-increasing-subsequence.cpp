class Solution {
public:
    int solve (int i, vector<int>&nums){
        if(i==nums.size())return 0;

        int nottake=solve(i+1,nums);
        int take=INT_MIN;
        if(i<nums.size()-1){
            if(nums[i]<nums[i+1]){
                take=1+solve(i+1,nums);
            }
        }
        return max(take,nottake);
    }
    int lengthOfLIS(vector<int>& nums) {
        return 1+solve(0,nums);
    }
};