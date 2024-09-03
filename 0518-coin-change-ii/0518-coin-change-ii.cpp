class Solution {
public:
    void solve(int amount, vector<int>& coins, int& count, int curr, vector<vector<int>>& memo) {
        if (amount == 0) {
            count++;
            return;
        }
        if (amount < 0) {
            return;
        }
        if (memo[curr][amount] != -1) {
            count += memo[curr][amount];
            return;
        }

        int ways = 0;
        for (int i = curr; i < coins.size(); i++) {
            solve(amount - coins[i], coins, ways, i, memo);
        }

        memo[curr][amount] = ways;
        count += ways;
    }

    int change(int amount, vector<int>& coins) {
        vector<vector<int>> memo(coins.size(), vector<int>(amount + 1, -1));
        int count = 0;
        solve(amount, coins, count, 0, memo);
        return count;
    }
};
