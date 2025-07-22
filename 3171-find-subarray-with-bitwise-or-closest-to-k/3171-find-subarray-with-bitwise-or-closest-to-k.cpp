class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> bit(32, 0);
        int l = 0, r = 0;
        int mini = INT_MAX;

        while (r < n) {
            int temp = nums[r];
            for (int i = 0; i < 32; i++) {
                if (temp & (1 << i)) bit[i]++;
            }

            int curr_or = 0;
            for (int i = 0; i < 32; i++) {
                if (bit[i] > 0) curr_or |= (1 << i);
            }

            int val = abs(k - curr_or);
            mini = min(mini, val);
            if (val == 0) return 0;

            if (curr_or < k) {
                r++;
            } else {
                while (curr_or > k && l < r) {
                    int temp1 = nums[l];
                    for (int i = 0; i < 32; i++) {
                        if (temp1 & (1 << i)) bit[i]--;
                    }

                    curr_or = 0;
                    for (int i = 0; i < 32; i++) {
                        if (bit[i] > 0) curr_or |= (1 << i);
                    }

                    val = abs(k - curr_or);
                    mini = min(mini, val);
                    if (val == 0) return 0;

                    l++;
                }
                r++;
            }
        }

        return mini;
    }
};
