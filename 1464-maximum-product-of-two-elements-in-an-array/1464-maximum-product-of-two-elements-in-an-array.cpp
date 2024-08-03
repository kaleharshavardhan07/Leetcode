class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int t=nums.size();

        int i=nums[t-1];
        int j=nums[t-2];
        int a=nums[0];
        int b=nums[1];
        return max((i-1)*(j-1), (a-1)*(b-1));
    }
};