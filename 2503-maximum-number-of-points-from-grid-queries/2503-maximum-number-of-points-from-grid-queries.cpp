class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size(), n = grid[0].size();
        vector<int> ret(queries.size(), 0);
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        // Sorting queries and tracking original indices
        vector<pair<int, int>> sorted_queries;
        for (int i = 0; i < queries.size(); i++)
            sorted_queries.push_back({queries[i], i});
        sort(sorted_queries.begin(), sorted_queries.end());

        // Min-Heap to expand the lowest grid values first
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        pq.push({grid[0][0], {0, 0}});
        vis[0][0] = true;

        int count = 0, index = 0;
        vector<int> dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};

        while (index < queries.size()) {
            int q = sorted_queries[index].first, qIndex = sorted_queries[index].second;

            // Expand all reachable cells whose values are less than `q`
            while (!pq.empty() && pq.top().first < q) {
                auto [val, pos] = pq.top();
                pq.pop();
                int i = pos.first, j = pos.second;
                count++;

                for (int d = 0; d < 4; d++) {
                    int ni = i + dx[d], nj = j + dy[d];
                    if (ni >= 0 && ni < m && nj >= 0 && nj < n && !vis[ni][nj]) {
                        vis[ni][nj] = true;
                        pq.push({grid[ni][nj], {ni, nj}});
                    }
                }
            }

            // Assign the answer for this query
            ret[qIndex] = count;
            index++;
        }

        return ret;
    }
};
