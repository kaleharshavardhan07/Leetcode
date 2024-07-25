#include<vector>
class Solution {
public:
    void seti(vector<int>& nums1, vector<int>& nums2, set<int>& st) {
        int l = 0;
        int r = 0;
        while (l < nums1.size() && r < nums2.size()) {
            if (nums1[l] == nums2[r]) {
                st.insert(nums1[l]);
                l++;
                r++;

            } else if (nums1[l] > nums2[r]) {
                r++;
            } else {
                l++;
            }
        }
    }
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2,
                              vector<int>& nums3) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        sort(nums3.begin(), nums3.end());

        set<int> st;
        seti(nums1, nums2, st);
        seti(nums2, nums3, st);
        seti(nums1, nums3, st);
        set<int>::iterator itr;
        vector<int> ret;
        for (itr = st.begin(); itr != st.end(); itr++) {
            ret.push_back(*itr);
        }
        return ret;
    }
};