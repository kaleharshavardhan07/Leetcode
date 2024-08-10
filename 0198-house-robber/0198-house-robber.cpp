class Solution {
public:
int solve(int n, vector<int>&dp, vector<int>&nums){
    if(n==0)return nums[0];
    if(n<0){return 0;}
    if(dp[n]!=-1)return dp[n];
    int pick=nums[n]+solve(n-2,dp,nums);
    int notpick=0+solve(n-1,dp,nums);
    return dp[n]=max(pick,notpick);
}
    int rob(vector<int>& nums) {
        

        int n=nums.size();
        vector<int>dp(n,-1);
        return solve(n-1, dp, nums);
    }
};