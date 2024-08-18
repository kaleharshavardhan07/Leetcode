class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int> ret(nums.size() + 1, 0);
        for (int n : nums) {
            if (ret[n] == 0)
                ret[n] += 1;
            else
                return n;
        }
        return nums.size()+1;
    }
};