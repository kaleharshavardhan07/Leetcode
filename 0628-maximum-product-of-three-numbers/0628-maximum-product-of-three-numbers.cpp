class Solution {
public:
    int maximumProduct(vector<int>& nums) {
       sort(nums.begin(),nums.end());
       int k=nums.size()-1;
       int i=nums[0]*nums[1]*nums[k];
       int j= nums[k]*nums[k-1]*nums[k-2];
       return max(i,j);
    }
};