class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        return helper(nums, 0, 0);
    }

    int helper(vector<int>& nums, int index, int currXOR) {
        if (index == nums.size()) 
            return currXOR;  

        int include = helper(nums, index + 1, currXOR ^ nums[index]);
        
        int exclude = helper(nums, index + 1, currXOR);

        return include + exclude;
    }
};
