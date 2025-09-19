class Solution {
public:
    int kadanealgo(vector<int>& arr) {
        int maxSum = arr[0];
        int currSum = arr[0];

        for (int i = 1; i < arr.size(); i++) {
            currSum = max(arr[i], currSum + arr[i]);
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }

    int maxFrequency(vector<int>& nums, int k) {
        int maxii = 0;

        int n = nums.size();

        int baseK = 0; 
        for (int x : nums) if (x == k) baseK++;
        for (int i = 1; i <= 50; i++) {

            if( i!=k){

            vector<int> ret(nums.size(), 0);
            for (int j = 0; j < n; j++) {
                if (nums[j] == i) {
                    ret[j] = 1;
                } else if (nums[j] == k)
                    ret[j] = -1;
                else {
                    ret[j] = 0;
                }
            }
            
            int cnt = kadanealgo(ret);
            maxii = max(cnt, maxii);}
        }
        return maxii+baseK;
    }
};