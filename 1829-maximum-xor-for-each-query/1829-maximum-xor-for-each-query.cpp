class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int maxi = 1 << maximumBit;
        maxi--;
        vector<int> ret;
        int sum = 0;
        for (int i : nums) {
            sum = sum ^ i;
            int temp = sum ^ maxi;
            ret.push_back(temp);
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};