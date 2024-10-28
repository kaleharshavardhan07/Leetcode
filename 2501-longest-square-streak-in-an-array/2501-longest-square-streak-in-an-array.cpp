class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> mapi;
        for (int n : nums) {
            mapi[n]++;
        }
        int maxc = 1;
        for (int i = 0; i < nums.size(); i++) {
            int flag = 1;
            int count = 1;
            int temp = nums[i] * nums[i];
            while (flag == 1) {
                if (mapi.find(temp) == mapi.end()) {
                    flag = 0;
                    maxc = max(maxc, count);
                }
                else{
                    count++;
                    temp=temp*temp;
                      maxc = max(maxc, count);

                }
            }

        }
        if( maxc==1)return -1;
        return maxc;
    }
};