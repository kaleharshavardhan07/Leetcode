class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int>ret;
        for(int n:nums){
            ret.push_back(nums[n]);}
            return ret;
    }
};