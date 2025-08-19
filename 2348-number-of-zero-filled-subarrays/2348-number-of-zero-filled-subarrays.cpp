class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long c = 0;
        long long ans = 0;

        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] == 0)
                c++;

            else {
                if (c > 0) {
                    ans = ans + c * (c + 1) / 2;
                    c = 0;
                } else {
                    continue;
                }
            }
        }
        if (c > 0) {
            ans = ans + c * (c + 1) / 2;
            c = 0;
        }
        return ans;
    }
};