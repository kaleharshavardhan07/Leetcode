

class Solution {
public:
    int solve(int start, int end, vector<int>& nums,
              vector<vector<int>>& memo) {
        if (start == end) {
            return nums[start];
        }

        if (memo[start][end] != INT_MIN) {
            return memo[start][end];
        }

        int chooseStart = nums[start] - solve(start + 1, end, nums, memo);
        int chooseEnd = nums[end] - solve(start, end - 1, nums, memo);

        memo[start][end] = max(chooseStart, chooseEnd);
        return memo[start][end];
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> memo(n, vector<int>(n, INT_MIN));
        int result = solve(0, n - 1, nums, memo);
        return result >= 0;
    }
};