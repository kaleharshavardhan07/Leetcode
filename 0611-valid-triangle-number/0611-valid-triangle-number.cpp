class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        int c=0;
        for( int i=n-1;i>=2;i--){

            int left=0;
            int right = i-1;
            while( left<right){
                 if (nums[left] + nums[right] > nums[i]) {
                    c += right - left;
                    right--;
                } else {
                    left++;
                }
            }

        }
        return c;
    }
};
// class Solution {
// public:
//     int triangleNumber(vector<int>& nums) {
//         int k = nums.size();
//         int c = 0;
//         for (int i = 0; i < k; i++) {
//             for (int j = i + 1; j < k; j++) {
//                 for (int z = j + 1; z < k; z++) {
//                     if (nums[j] + nums[z] > nums[i] &&
//                         nums[i] + nums[z] > nums[j] &&
//                         nums[j] + nums[i] > nums[z]) {
//                         c++;
//                     }
//                 }
//             }
//         }
//         return c;
//     }
// };