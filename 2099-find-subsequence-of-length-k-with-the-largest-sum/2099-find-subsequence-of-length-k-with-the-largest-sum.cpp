class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {

        vector<int> temp = nums;
        sort(temp.begin(), temp.end());

        reverse(temp.begin(), temp.end());
        vector<int> ret;
        for (int i = 0; i < nums.size(); i++) {
            int t = nums[i];
           
            for (int j = 0; j < k; j++) {
                if (temp[j] == t) {
                    ret.push_back(t);
                     temp[j] = INT_MAX;
                    break;
                   
                }
            }
        }
        return ret;
    }
};

// for nums
// class Solution {
// public:
//     vector<int> maxSubsequence(vector<int>& nums, int k) {
//         int maxi = 0;
//         int lowi = INT_MAX;

//         int c = 0;
//         int sum = 0;

//         for (int i = 0; i < nums.size(); i++) {
//             if (c < k) {
//                 sum = sum + nums[i];
//                 c++;
//                 lowi = min(lowi, nums[i]);

//             } else if (lowi < nums[i]) {
//                 sum -= lowi;
//                 sum += nums[i];
//                 lowi = nums[i];
//             }

//             if (c == k) {
//                 maxi = max(maxi, sum);
//             }
//         }
//         return maxi;
//     }
// };