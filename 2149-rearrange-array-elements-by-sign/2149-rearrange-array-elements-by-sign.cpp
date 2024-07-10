class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> neg;
        vector<int> pov;
        for (int a : nums) {
            if (a < 0) {
                neg.push_back(a);

            } else {
                pov.push_back(a);
            }
        }
        vector<int> ret;
        for (int i = 0; i < neg.size(); i++) {
            ret.push_back(pov[i]);
            ret.push_back(neg[i]);
        }
        return ret;
    }
};