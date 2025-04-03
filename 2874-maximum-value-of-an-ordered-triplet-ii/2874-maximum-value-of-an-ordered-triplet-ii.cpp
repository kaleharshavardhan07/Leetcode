class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {

        long long maxi = 0;
        long long sum = 0;
        long long maxxx = nums[0];
        int n = nums.size();
        for (int i = 0; i < n-1; i++) {

            maxi = max<long long>(maxi, maxxx - nums[i]);

            sum = max<long long>(sum, maxi * nums[i + 1]);

            maxxx = max<long long>(maxxx, nums[i]);
        }

        return sum;
    }
};