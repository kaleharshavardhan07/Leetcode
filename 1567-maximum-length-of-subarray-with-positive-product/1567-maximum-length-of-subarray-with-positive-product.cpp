class Solution {
public:
    
int getMaxLen(vector<int>& nums) {
    int pos_len = 0;  // Length of the current positive product subarray
    int neg_len = 0;  // Length of the current negative product subarray
    int max_len = 0;  // Maximum length of a subarray with a positive product

    for (int num : nums) {
        if (num > 0) {
            // Positive number: extend positive subarray and potentially extend negative subarray
            pos_len = pos_len + 1;
            neg_len = (neg_len == 0) ? 0 : neg_len + 1;
        } else if (num < 0) {
            // Negative number: swap positive and negative subarrays
            int temp = pos_len;
            pos_len = (neg_len == 0) ? 0 : neg_len + 1;
            neg_len = temp + 1;
        } else {
            // Zero: reset both subarray lengths
            pos_len = 0;
            neg_len = 0;
        }

        // Update the maximum length of subarrays with a positive product
        max_len = max(max_len, pos_len);
    }

    return max_len;
}
};