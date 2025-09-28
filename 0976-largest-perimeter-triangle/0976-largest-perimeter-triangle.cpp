class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort( nums.begin(),nums.end());
        int n= nums.size();
        int maxi=0;
       for (int i = n - 1; i >= 2; --i){
             if (nums[i - 2] + nums[i - 1] > nums[i]) {
                return nums[i - 2] + nums[i - 1] + nums[i];
            }
            // for( int j=i+1;j<n;j++){
            //     for( int k=j+1;k<n;k++){
            //         if( nums[i]+nums[j]>nums[k] &&  nums[i]+nums[k]>nums[j] && nums[k]+nums[j]>nums[i]){
            //             return nums[i]+nums[j]+nums[k];
            //         }
            //     }
            // }
        }
        return maxi;
    }
};