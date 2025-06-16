class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int maxi=-1;
        for( int i=0;i< nums.size();i++){
            for( int j=0;j<i;j++){
                if( nums[i]>nums[j])
                maxi= max(maxi,nums[i]-nums[j]);

            }
        }
        return maxi;
    }
};