class Solution {
public:
    long long cp(int n) { return (n * (n - 1)) / 2; }
    long long countGood(vector<int>& nums, int k) {

        int l = 0;
        int r = 0;
        long long c = 0;
        long long s = 0;
       unoredered_map<int, int> mp;
        int n = nums.size();
        while (l < n) {
            while (r < n && c < k) {
                c += mp[nums[r]];
                mp[nums[r]]++;
                r++;
            }

            if (c >= k) {
                s += n - r + 1;
            }

            c -= mp[nums[l]] - 1;
            mp[nums[l]]--;
            l++;
        }
        return s;
    }
};