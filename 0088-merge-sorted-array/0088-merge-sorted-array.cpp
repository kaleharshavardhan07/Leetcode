class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = nums1.size() - 1;

        while (m-1 >= 0 && n-1 >= 0 && k >= 0) {
            if (nums1[m - 1] > nums2[n - 1]) {
                nums1[k] = nums1[m - 1];
                k--;
                m--;
            } else {
                nums1[k] = nums2[n - 1];
                n--;
                k--;
            }
        }
        while (m-1 >= 0 && k >= 0) {
            nums1[k] = nums1[m - 1];
            k--;
            m--;
        }
        while (n-1 >= 0 && k >= 0) {
            nums1[k] = nums2[n - 1];
            n--;
            k--;
        }
    }
};