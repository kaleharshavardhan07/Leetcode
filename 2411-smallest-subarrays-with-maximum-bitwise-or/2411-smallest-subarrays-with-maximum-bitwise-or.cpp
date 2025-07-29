class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        vector<int> ret;
        int ri = 0;
        for (int n : nums) {
            ri = ri | n;
        }
        for (int i = 0; i < nums.size(); i++) {
            int maxi = 0;
            int curr = 0;
            int l = 1;
            for (int j = i; j < nums.size(); j++) {

                curr = curr | nums[j];
                if (curr > maxi) {
                    maxi = curr;
                    l = j - i + 1;
                }
                if( curr==ri)break;
            }
            ret.push_back(l);
        }
        return ret;
    }
};