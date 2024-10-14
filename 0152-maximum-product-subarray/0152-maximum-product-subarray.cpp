class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int maxp=nums[0];
        int minp=nums[0];
        int prod=nums[0];

        for( int i=1;i<nums.size();i++){
            if( nums[i]<0){
                swap(minp,maxp);
            }

            maxp = max(nums[i], nums[i] * maxp);
            minp = min(nums[i], nums[i] * minp);
            prod=max(prod,maxp);

        }
        return prod;
        
    }
};