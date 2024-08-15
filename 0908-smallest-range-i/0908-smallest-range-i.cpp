class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
       sort(nums.begin(),nums.end());
        int mid=(nums[0]+nums[nums.size()-1])/2;
        int mini=k+nums[0];
        int maxi=nums[nums.size()-1]-k;
        if(mini>=maxi)return 0;

        return maxi-mini;
        

       
    }
};