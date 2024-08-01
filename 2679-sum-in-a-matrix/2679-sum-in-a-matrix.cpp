class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        for (int i = 0; i < nums.size(); i++) {

            sort(nums[i].begin(), nums[i].end());
        }
        int m = 0;
        for (int i = 0; i < nums.size(); i++) {
            int maxi= 0;
            for (int j = 0; j < nums[0].size(); j++) {
                maxi = max(maxi, nums[j][i]);
            }

            m += maxi;
        }
        return m;
    }
};