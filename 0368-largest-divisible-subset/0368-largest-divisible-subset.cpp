class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ret;

        for (int i = 0; i < nums.size(); i++) {
            int curr = nums[i];
            vector<int> temp;
            temp.push_back(curr);
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] % curr == 0) {
                    curr = nums[j];
                    temp.push_back(curr);
                }
            }
            if(temp.size()>ret.size()){
                ret=temp;
            }
        }
        return ret;
    }
};