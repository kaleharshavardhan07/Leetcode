class Solution {
public:
    void solve(int amount, vector<int>& coins, int& count, int curr) {
        if (amount == 0) {
            count++;
            return ;
        }
        if (amount < 0)
            return ;

        for (int i=curr;i<coins.size();i++) {
            solve(amount - coins[i], coins, count,i);
        }
    }
    int change(int amount, vector<int>& coins) {
        sort(coins.begin(),coins.end());
        vector<int> memo(amount + 1, -1);
        int count = 0;
        solve(amount, coins, count,0);
        return count;
    }
};