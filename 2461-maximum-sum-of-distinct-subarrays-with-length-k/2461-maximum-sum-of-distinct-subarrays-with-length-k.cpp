class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if (k > n)
            return -1;
        long long sum = 0;
        unordered_map<int, int> mapi;
        long long fsum = 0;
        for (int i = 0; i < k; i++) {
            mapi[nums[i]]++;
            fsum += nums[i];
        }
        if (mapi.size() == k) {
            sum = max(fsum, sum);
        }

        for (int i = k; i < n; i++) {
            mapi[nums[i]]++;
            mapi[nums[i - k]]--;
            fsum += nums[i];
            fsum -= nums[i - k];
            if (mapi[nums[i - k]] == 0) {
                mapi.erase(nums[i - k]);
            }
            if (mapi.size() == k)
                sum = max(fsum, sum);
        }
        return sum;
    }
};