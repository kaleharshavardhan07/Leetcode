class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {

        // vector<long long> ret;
        // long long s = 0;
        // for (int i : nums) {
        //     s = s + i;
        //     ret.push_back(s);
        // }
        long long c = 0;
        int l = 0;
        long long s=0;
        for( int r=0;r<nums.size();r++){
           s=s+nums[r];
           while(s * (r - l + 1) >= k){
            s=s-nums[l];
            l++;
           }
           c=c+r-l+1;
        }
        return c;
    }
};