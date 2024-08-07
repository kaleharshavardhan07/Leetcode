class Solution {
public:
    int calli(const std::vector<std::pair<int, int>> adj[], int n, int start, int threshold) {
        std::vector<int> dist(n, std::numeric_limits<int>::max());
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
        
        dist[start] = 0;
        pq.push({0, start});
        
        while (!pq.empty()) {
            int u = pq.top().second;
            int d = pq.top().first;
            pq.pop();
            
            if (d > dist[u]) continue;
            
            for (const auto& neighbor : adj[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;
                
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }
        
        // Count cities within the distance threshold
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (dist[i] <= threshold) {
                ++count;
            }
        }
        return count;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<pair<int, int>> adj[n + 1];
        int k = distanceThreshold;
        for (auto e : edges) {
            adj[e[0]].push_back(make_pair(e[1], e[2]));
            adj[e[1]].push_back(make_pair(e[0], e[2]));
        }
        int maxi = -1;
        int count = INT_MAX;
        for (int i = 0; i < n ; i++) {
            int j = calli(adj,n, i, k);
            if (j <= count) {
                maxi = i;
                count = j;
            }
        }
        return maxi;
    }
};