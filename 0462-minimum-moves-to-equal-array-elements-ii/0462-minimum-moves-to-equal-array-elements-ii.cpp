class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort( nums.begin(),nums.end());
        int k=med(nums);
        int sum=0;
        for( int i: nums){
            sum=sum+abs(i-k);
        }

        return sum;
    
    }
    int med( vector<int>&nums){
        int n = nums.size();
    if (n % 2 != 0) {
        
        return nums[n / 2];
    } else {
       
        return (nums[(n - 1) / 2] + nums[n / 2]) / 2.0;
    }
    }
};