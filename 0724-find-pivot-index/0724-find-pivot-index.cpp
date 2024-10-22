class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int csum=0;
        int sum=0;
        for( int n: nums)sum+=n;

        for( int i=0;i<nums.size();i++){
            if( csum==sum-csum-nums[i]){
                return i;
            }
            csum+=nums[i];
        }
        return -1;

    }
};