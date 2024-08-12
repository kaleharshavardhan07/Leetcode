class Solution {
public:
    int triangularSum(vector<int>& nums) {
        vector<int> ret = nums;
        int k = ret.size();
        if(k==1)return ret[0];
        while (k > 1) {
            // vector<int>r(ret.size()-1);
            for (int i = 0; i <k-1; ++i) {

                ret[i] = (ret[i] + ret[i + 1]) % 10;
            }
            k--;
            //    ret=r;
        }
        if (ret.size() == 0) {
            return -1;
        }
        return ret[0];
    }
};