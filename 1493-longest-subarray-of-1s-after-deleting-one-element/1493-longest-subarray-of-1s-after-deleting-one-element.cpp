class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int lastpos = -1;
        int c = 0;
        int maxi = 0;
        int count=0;
        int left = 0;
        while (left < nums.size()) {
            if (nums[left] == 0) {
                if (c == 0) {
                    c++;
                    lastpos = left;
                    left++;
                    count++;
                } else {
                    left = lastpos + 1;
                    lastpos=-1;
                    maxi=max(maxi,count-1);
                    count=0;
                    c=0;
                }
            }
            else{
                count++;
                left++;

            }
        }
        return max(maxi,count-1);

    }
};