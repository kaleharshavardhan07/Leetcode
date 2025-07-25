class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        int l = 0;
        int r = 1;
        long long c = 0;
        while (r < nums.size()) {
            if (nums[r] != nums[r - 1]) {
              
                c = c + (r - l);
                  r++;

            } else {
                
                l = r;
                r++;
            }
        }
        return c +nums.size();
    }
};