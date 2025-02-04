class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxi=nums[0];
        int temp=nums[0];
        for( int i=1;i<nums.size();i++){
            if( nums[i]>nums[i-1]){
                temp+=nums[i];
            }
            else{
                temp=nums[i];
            }
            maxi=max(maxi,temp);
        }
        return maxi;
    }
};