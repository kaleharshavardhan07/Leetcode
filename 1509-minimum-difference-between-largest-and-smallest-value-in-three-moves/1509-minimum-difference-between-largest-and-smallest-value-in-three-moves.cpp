class Solution {
public:
    int minDifference(vector<int>& nums) {
        if(nums.size()<=4){
            return 0;
        }
        int k=nums.size();
        
        sort(nums.begin(),nums.end());
        int a=nums[k-4]-nums[0];
        int b=nums[k-1]-nums[3];
        int c=nums[k-3]-nums[1];
        int d=nums[k-2]-nums[2];
         int minimum_value = min({a, b, c, d});

        return minimum_value;
        
    }
};