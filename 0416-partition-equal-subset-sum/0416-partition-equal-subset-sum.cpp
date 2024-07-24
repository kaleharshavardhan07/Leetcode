class Solution {
public:
    bool canPartition(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l = 0;
        int r = nums.size() - 1;
        int suml = nums[0];
        int sumr = nums[r];
        while (l < r) {

            if (sumr > suml) {

                l++;
                suml += nums[l];
            } else if (sumr < suml) {
                r--;
                sumr += nums[r];
            } else if (sumr == suml) {
                if (r-l==1)
                    return true;
                else{
                    l++;r--;
                }
            }
        }
        return false;
    }
};