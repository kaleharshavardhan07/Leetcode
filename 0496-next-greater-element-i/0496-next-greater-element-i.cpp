class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mapi;
        int k = nums2.size();
        for (int i = 0; i < k; i++) {
            int curm = -1;
            for (int j = i + 1; j < k; j++) {
                if (nums2[j] > nums2[i]) {
                    curm = nums2[j];
                    break;
                }
            }
            mapi[nums2[i]] = curm;
        }
        vector<int> ret;
        for (int n : nums1) {
            ret.push_back(mapi[n]);
        }
        return ret;
    }
};