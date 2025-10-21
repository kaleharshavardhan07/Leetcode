// class Solution {
// public:
//     int find(int i, vector<int>& nums, int k) {
//         int n = nums.size();
//         int low = i - k;
//         int high = i + k;

//         int left = lower_bound(nums.begin(), nums.end(), low) - nums.begin();
//         int right = upper_bound(nums.begin(), nums.end(), high) - nums.begin() - 1;

//         if (left >= n || right < 0 || left > right)
//             return 0;

//         return right - left + 1;
//     }

//     int maxFrequency(vector<int>& nums, int k, int numOperations) {

//         map<int, int> mp;
//         int maxm = 1;
//         int n = nums.size();

//         for (int val : nums) {
//             mp[val]++;
//             maxm = max(maxm, mp[val]);
//         }

//         int maxi = 0;

//         for (auto &p : mp) {
//             int val = p.first;
//             int tot = find(val, nums, k);  

//             int sm = p.second;

//             int arc = min(tot, sm + numOperations);

//             maxi = max(maxi, arc);
//         }

//         return max(maxi, maxm);
//     }
// };



class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int maxVal = *max_element(nums.begin(), nums.end()) + k + 2;
        int* count = new int[maxVal]();

        for (int v : nums)
            count[v]++;

        for (int i = 1; i < maxVal; i++)
            count[i] += count[i - 1];

        int res = 0;
        for (int i = 0; i < maxVal; i++) {
            int left = max(0, i - k);
            int right = min(maxVal - 1, i + k);
            int total = count[right] - (left ? count[left - 1] : 0);
            int freq = count[i] - (i ? count[i - 1] : 0);
            res = max(res, freq + min(numOperations, total - freq));
        }

        return res;
    }
};
