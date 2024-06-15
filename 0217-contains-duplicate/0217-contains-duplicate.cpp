class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int k=nums.size();
        for(int i=0;i<k;i++){
            if(i <k-1 && nums[i]==nums[i+1]){
                return true;
            }
        }
        return false;
    }
};