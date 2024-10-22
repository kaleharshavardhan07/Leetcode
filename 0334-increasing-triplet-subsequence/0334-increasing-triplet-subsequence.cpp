class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
      int n=nums.size();
        if(n<3)return false;
        int a=INT_MAX,b=INT_MAX;
        for(int i=0;i<n;i++){
            if(nums[i]<=a)a=nums[i];
            else if(nums[i]<=b)b=nums[i];
            else return true;
        }
        return false;
    
    }
};


// class Solution {
// public:
//     bool increasingTriplet(vector<int>& nums) {
//         int n = nums.size();
//         int maxi = 1;
//         vector<int> dp(n, 1);
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < i; j++) {
//                 if (nums[j] < nums[i]) {
//                     dp[i] = max(dp[i], dp[j] + 1);
//                 }
//                 if (dp[i] >= 3)
//                     return true;
//             }
//             maxi = max(maxi, dp[i]);
//             if (maxi >= 3) {
//                 return true;
//             }
//         }
//         if (maxi >= 3) {
//             return true;
//         }
//         return false;
//     }
// };