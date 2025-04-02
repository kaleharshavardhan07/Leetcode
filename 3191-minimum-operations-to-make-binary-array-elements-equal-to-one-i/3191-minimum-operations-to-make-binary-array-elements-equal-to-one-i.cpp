class Solution {
public:
    int minOperations(vector<int>& nums) {
        int l=0;
        int n=nums.size();
        int c=0;
        while(l<n-2){
            if(nums[l]==0){
                nums[l]^=1;
                nums[l+1]^=1;
                nums[l+2]^=1;
               c++;
                
            }
            l++;
        }
        if(nums[n-2]==0 || nums[n-1]==0)return -1;
        return c;
    }
};