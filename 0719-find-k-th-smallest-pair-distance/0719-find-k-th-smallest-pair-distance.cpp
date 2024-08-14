class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        vector<int>ret;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                ret.push_back(abs(nums[i]-nums[j]));
            }
        }
        sort(ret.begin(),ret.end());
        if(ret.size()<k)return-1;
         return ret[k-1];
    }
};