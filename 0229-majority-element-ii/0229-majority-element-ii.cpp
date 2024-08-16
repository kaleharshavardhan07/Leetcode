class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ret;
        int temp = nums.size() / 3;
        unordered_map<int, int> mapi;
        for (int n : nums) {
            mapi[n]++;
        }
        for (auto it : mapi) {
            if (it.second > temp) {
                ret.push_back(it.first);
            }
        }
        return ret;
    }
};