class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int, vector<int>, greater<int>> pq1;
        priority_queue<int, vector<int>, greater<int>> pq2;

        int l = 0;
        int r = costs.size() - 1;
        for (int i = 0; i < candidates && l <= r; ++i) {
            pq1.push(costs[l++]);
        }
        for (int i = 0; i < candidates && l <= r; ++i) {
            pq2.push(costs[r--]);
        }

        long long ans = 0;
        while (k--) {
            int left = pq1.empty() ? INT_MAX : pq1.top();
            int right = pq2.empty() ? INT_MAX : pq2.top();

            if (left <= right) {
                ans += left;
                pq1.pop();
                if (l <= r) {
                    pq1.push(costs[l++]);
                }
            } else {
                ans += right;
                pq2.pop();
                if (l <= r) {
                    pq2.push(costs[r--]);
                }
            }
        }

        return ans;
    }
};