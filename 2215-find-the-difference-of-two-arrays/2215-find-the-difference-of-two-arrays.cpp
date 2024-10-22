// class Solution {
// public:
//     vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {

//         sort(nums1.begin(), nums1.end());
//         sort(nums2.begin(), nums2.end());
//         int k = nums1.size();
//         int h = nums2.size();
//         int i = 0;
//         int j = 0;
//         vector<int> k1;
//         vector<int> k2;

//         while (i < k && j < h) {
//             if (nums1[i] == nums2[j]) {
//                 i++;
//                 j++;

//             } else if (nums1[i] < nums2[j]) {
//                 k1.push_back(nums1[i]);
//                 i++;
//             } else if (nums1[i] > nums2[j]) {
//                 k2.push_back(nums2[j]);
//                 j++;
//             }
//         }
//         while(i<k){
//              k1.push_back(nums1[i]);
//              i++;
//         }
//         while(j<h){
//              k2.push_back(nums2[j]);
//              j++;
//         }

//         vector<vector<int>> output;
//         output.push_back(k1);
//         output.push_back(k2);
//         return output;
//     }
// };

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        // Use unordered sets to keep track of unique elements
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());
        
        vector<int> k1;
        vector<int> k2;

        // Find elements in nums1 that are not in nums2
        for (int num : nums1) {
            if (set2.find(num) == set2.end()) {
                k1.push_back(num);
                set2.insert(num);  // Insert into set2 to avoid duplicates in k1
            }
        }

        // Find elements in nums2 that are not in nums1
        for (int num : nums2) {
            if (set1.find(num) == set1.end()) {
                k2.push_back(num);
                set1.insert(num);  // Insert into set1 to avoid duplicates in k2
            }
        }

        return {k1, k2};
    }
};