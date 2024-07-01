class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.size()<2){
            return nums[0];
        }
        sort(nums.begin(),nums.end());
      int k;
        for(int i=0;i<nums.size();i+=2){
            if(nums[i]!=nums[i+1]){
                k= nums[i];
                break;
            }
        }
        return k;
    }
};